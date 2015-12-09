//
//  EZOpenSDK.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/9/10.
//  Copyright (c) 2015年 Hikvision. All rights reserved.
//

#import <UIKit/UIKit.h>

/* EZOpenSDK的错误定义 */
typedef NS_ENUM(NSInteger, EZErrorCode) {
    EZ_DEVICE_OFFLINE = 400121,  //设备不在线
    EZ_PLAY_TIMEOUT = 380209,    //网络连接超时
    EZ_DEVICE_TIMEOUT = 380212,  //设备端网络连接超时
    EZ_DEVICE_CONNECT_COUNT_LARGEST = 340410, //设备取流连接数量超过最大值
    EZ_DEVICE_QUERY_RECORD_FAILED = 380005,  //远程SD卡搜索录像失败
    EZ_DEVICE_LOCAL_SIGNIN_FAILED = 332006, //局域网登录设备失败
    EZ_DEVICE_TTS_TALKING = 360010, //设备正在对讲中
    EZ_DEVICE_CAS_TALKING = 380077, //设备正在对讲中
    EZ_DEVICE_IS_PRIVACY_PROTECTING =380011, //设备隐私保护中
    EZ_DEVICE_BUNDEL_STATUS_ON = 380128, //设备开启了终端绑定，未绑定客户端无法取流
    EZ_DEVICE_COMMAND_NOT_SUPPORT = 380047, //设备不支持该命令
    EZ_DEVICE_NOT_EXIST = 120002, //设备不存在
    EZ_DEVICE_ONLINE_NOT_ADDED = 120021, //设备在线，未被用户添加
    EZ_DEVICE_ONLINE_IS_ADDED = 120022, //设备在线，已经被别的用户添加
    EZ_DEVICE_OFFLINE_NOT_ADDED = 120023, //设备不在线，未被用户添加
    EZ_DEVICE_OFFLINE_IS_ADDED = 120024, //设备不在线，已经被别的用户添加
};

/* 播放器状态消息 */
typedef NS_ENUM(NSInteger, EZMessageCode)
{
    PLAYER_NEED_VALIDATE_CODE = -1, //播放需要安全验证
    PLAYER_REALPLAY_START = 1,   //直播开始
    PLAYER_VIDEOLEVEL_CHANGE = 2, //直播流清晰度切换中
    PLAYER_STREAM_RECONNECT = 3,  //直播流取流正在重连
    PLAYER_PLAYBACK_START = 11, //录像回放开始播放
    PLAYER_PLAYBACK_STOP = 12   //录像回放结束播放
};

/* WiFi配置设备状态 */
typedef NS_ENUM(NSInteger, EZWifiConfigStatus)
{
    DEVICE_WIFI_CONNECTING = 1, //设备正在连接WiFi
    DEVICE_WIFI_CONNECTED = 2, //设备连接WiFi成功
    DEVICE_PLATFORM_REGISTED = 3, //设备注册平台成功
    DEVICE_ACCOUNT_BINDED = 4 //设备已经绑定账户
};

/* 设备ptz命令 */
typedef NS_OPTIONS(NSUInteger, EZPTZCommand) {
    EZPTZCommandLeft            = 1 << 0, //向左旋转
    EZPtzCommandRight           = 1 << 1, //向右旋转
    EZPTZCommandUp              = 1 << 2, //向上旋转
    EZPTZCommandDown            = 1 << 3, //向下旋转
};

/* 
 * 设备显示命令 
 */
typedef NS_OPTIONS(NSUInteger, EZDisplayCommand)
{
    EZDisplayCommandCenter          = 1 << 0, //显示中间
    EZDisplayCommandLeftRight       = 1 << 1, //左右翻转
    EZDisplayCommandUpDown          = 1 << 2  //上下翻转
};

/**
 *  设备ptz动作命令
 */
typedef NS_ENUM(NSInteger, EZPTZAction){

    EZPTZActionStart = 1, //ptz开始
    EZPTZActionStop = 2  //ptz停止
};

/* 报警消息状态 */
typedef NS_ENUM(NSInteger, EZAlarmStatus)
{
    EZAlarmStatusRead = 1,    //已读
};

/* 短信类型 */
typedef NS_ENUM(NSInteger, EZSMSType) {
    EZSMSTypeSecure = 1,     //安全验证
};

@class EZPlayer;
@class EZDeviceInfo;
@class EZAccessToken;
@class EZCameraInfo;

@interface EZOpenSDK : NSObject

/**
 *  实例EZOpenSDK方法
 *
 *  @param appKey 传入申请的appKey
 *
 *  @return YES/NO
 */
+ (BOOL)initLibWithAppKey:(NSString *)appKey;

/**
 *  销毁EZOpenSDK方法
 *
 *  @return YES/NO
 */
+ (BOOL)destoryLib;

/**
 *  获取SDK版本号
 *
 *  @return 版本号
 */
+ (NSString *)getVersion;

/**
 *  打开授权登录中间页面
 *
 *  @param block 回调block
 */
+ (void)openLoginPage:(void (^)(EZAccessToken *accessToken))block;

/**
 *  授权登录以后给EZOpenSDK设置AccessToken
 *
 *  @param accessToken 授权登录获取的accessToken
 */
+ (void)setAccessToken:(NSString *)accessToken;

/**
 *  登出账号
 *
 *  @param completion 回调block
 */
+ (void)logout:(void (^)(id responseObject, NSError *error))completion;


/**
 *  打开设备设置中间页
 *
 *  @param deviceSerial 设备序列号
 */
+ (void)openSettingDevicePage:(NSString *)deviceSerial;

/**
 *  获取摄像头列表
 *
 *  @param pageIndex  分页当前页码（从0开始）
 *  @param pageSize   分页每页数量（建议20以内)
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)getCameraList:(NSInteger)pageIndex
                      pageSize:(NSInteger)pageSize
                    completion:(void (^)(NSArray *cameraList, NSError *error))completion;
/**
 *  获取设备详细信息
 *
 *  @param cameraId  设备摄像头id
 *  @param completion  回调block
 */
+ (void)getDeviceInfo:(NSString *)cameraId
            comletion:(void (^)(EZDeviceInfo *deviceInfo, NSError *error))completion;

/**
 *  获取指定设备的报警信息列表
 *
 *  @param cameraId   设备摄像头id
 *  @param pageIndex  分页当前页码（从0开始）
 *  @param pageSize   分页每页数量（建议20以内）
 *  @param beginTime  搜索时间范围开始时间
 *  @param endTime    搜索时间范围结束时间
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)getAlarmList:(NSString *)cameraId
                    pageIndex:(NSInteger)pageIndex
                     pageSize:(NSInteger)pageSize
                    beginTime:(NSDate *)beginTime
                      endTime:(NSDate *)endTime
                   completion:(void (^)(NSArray *alarmList, NSInteger alarmCount, NSError *error))completion;

/**
 *  删除报警信息
 *
 *  @param alarmIds   报警信息Id数组(可以只有一个Id),最多为10个Id,否则会报错。
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)deleteAlarm:(NSArray *)alarmIds
                  completion:(void (^)(id result, NSError *error))completion;

/**
 *  设置报警信息为已读
 *
 *  @param alarmId    报警信息Id数组(可以只有一个Id)，最多为10个id,否则会报错;
 *  @param status     报警消息状态
 *  @param completion 回调block
 *
 *  @return opeartion
 */
+ (NSOperation *)setAlarmStatus:(NSArray *)alarmIds
                    alarmStatus:(EZAlarmStatus)status
                     completion:(void (^)(id result, NSError *error))completion;

/**
 *  根据设备序列号删除当前账号的设备
 *
 *  @param deviceSerial  设备序列号
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)deleteDevice:(NSString *)deviceSerial
                   completion:(void (^)(id result, NSError *error))completion;

/**
 *  根据设备序列号查询摄像头信息，一般在设备添加WiFi配置之前先作一次查询，通过错误码来判断摄像头的状态(详情见枚举错误码)
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block
 *
 *  @return operation
 */
+ (NSOperation *)getCameraInfo:(NSString *)deviceSerial
                    completion:(void (^)(EZCameraInfo *cameraInfo, NSError *error))completion;

/**
 *  透传接口
 *
 *  @param transferInfo 透传接口信息(JSON字符串)
 *  @param completion   回调block
 *
 *  @return operation
 */
+ (NSOperation *)transferAPI:(NSString *)transferInfo
                  completion:(void (^)(id responseObject, NSError *error))completion;

/**
 *  查询云存储录像信息列表
 *
 *  @param cameraId   设备摄像头id
 *  @param beginTime  查询时间范围开始时间
 *  @param endTime    查询时间范围结束时间
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)searchRecordFileFromCloud:(NSString *)cameraId
                                 beginTime:(NSDate *)beginTime
                                   endTime:(NSDate *)endTime
                                completion:(void (^)(NSArray *couldRecords, NSError *error))completion;

/**
 *  查询远程SD卡存储录像信息列表
 *
 *  @param cameraId   设备摄像头id
 *  @param beginTime  查询时间范围开始时间
 *  @param endTime    查询时间范围结束时间
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)searchRecordFileFromDevice:(NSString *)cameraId
                                  beginTime:(NSDate *)beginTime
                                    endTime:(NSDate *)endTime
                                 completion:(void (^)(NSArray *deviceRecords, NSError *error))completion;

/**
 *  开始WiFi配置
 *
 *  @param ssid         连接WiFi SSID
 *  @param password     连接WiFi 密码
 *  @param deviceSerial 连接WiFi的设备的设备序列号
 *  @param statusBlock  返回连接设备的WiFi配置状态
 *
 *  @return YES/NO
 */
+ (BOOL)startConfigWifi:(NSString *)ssid
               password:(NSString *)password
           deviceSerial:(NSString *)deviceSerial
           deviceStatus:(void (^)(EZWifiConfigStatus status))statusBlock;

/**
 *  添加设备
 *
 *  @param deviceSerial 设备序列号
 *  @param deviceCode   设备验证码
 *  @param completion   回调block
 *
 *  @return operation
 */
+ (NSOperation *)addDevice:(NSString *)deviceSerial
                deviceCode:(NSString *)deviceCode
                completion:(void (^)(id result, NSError *error))completion;

/**
 *  停止Wifi配置
 *
 *  @return YES/NO
 */
+ (BOOL)stopConfigWifi;

/**
 *  PTZ 控制接口
 *
 *  @param command ptz控制命令
 *  @param action  控制启动/停止
 *  @param speed   速度 (取值范围：0-7整数值)
 *  @param resultBlock 回调block
 *
 *  @return YES/NO
 */
+ (BOOL)controlPTZ:(NSString *)cameraId
           command:(EZPTZCommand)command
            action:(EZPTZAction)action
             speed:(NSInteger)speed
            result:(void (^)(BOOL result, NSError *error))resultBlock;

/**
 *  摄像头显示控制接口
 *
 *  @param command     显示控制命令
 *  @param resultBlock 回调block
 *
 *  @return YES/NO
 */
+ (BOOL)controlDisplay:(NSString *)cameraId
               command:(EZDisplayCommand)command
                result:(void (^)(BOOL result, NSError *error))resultBlock;

/**
 *  根据cameraId构造EZPlayer对象
 *
 *  @param cameraId 摄像头Id
 *
 *  @return EZPlayer对象
 */
+ (EZPlayer *)createPlayerWithCameraId:(NSString *)cameraId;


/**
 *  根据url构造EZPlayer对象 （主要用来处理视频广场的播放）
 *
 *  @param url 播放url
 *
 *  @return EZPlayer对象
 */
+ (EZPlayer *)createPlayerWithUrl:(NSString *)url;


/**
 *  释放EZPlayer对象
 *
 *  @param player EZPlayer对象
 *
 *  @return YES/NO
 */
+ (BOOL)releasePlayer:(EZPlayer *)player;

#pragma mark - V3.1 新增加接口

/**
 *  数据解密
 *
 *  @param data     需要解密的数据
 *  @param password 解密密码
 *
 *  @return 解密的NSData对象
 */
+ (NSData *)decryptData:(NSData *)data password:(NSString *)password;

/**
 *  根据设备序列号从SDK获取设备验证码
 *
 *  @param deviceSerial 设备序列号
 *
 *  @return 设备验证码
 */
+ (NSString *)getValidteCode:(NSString *)deviceSerial;

/**
 *  向SDK设置设备序列号和设备验证码
 *
 *  @param validateCode 设备验证码
 *  @param deviceSerail 设备序列号
 */
+ (void)setValidateCode:(NSString *)validateCode forDeviceSerial:(NSString *)deviceSerail;

/**
 *  获取短信验证码接口
 *
 *  @param type       短信类型
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)getSMSCode:(EZSMSType)type completion:(void (^)(NSError *error))completion;

/**
 *  验证安全验证码接口
 *
 *  @param smsCode    获取到的手机短信安全验证码
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)secureSmsValidate:(NSString *)smsCode
                        completion:(void (^)(NSError *error))completion;

/**
 *  获取视频广场的频道列表
 *
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)getSquareChannelList:(void (^)(NSArray *squareColumns, NSError *error))completion;

/**
 *  获取视频广场公共资源视频列表
 *
 *  @param channelId  频道编号
 *  @param pageIndex  分页当前页码（从0开始）
 *  @param pageSize   分页每页数量（建议20以内）
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)getSquareVideoList:(NSInteger)channelId
                          pageIndex:(NSInteger)pageIndex
                           pageSize:(NSInteger)pageSize
                         completion:(void (^)(NSArray *videoList, NSInteger totalCount, NSError *error))completion;
/**
 *  收藏视频广场公共资源
 *
 *  @param videoId   视频Id
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)saveFavorite:(NSString *)videoId
                   completion:(void (^)(NSString *favoriteId, NSError *error))completion;
/**
 *  取消收藏的视频广场公共资源
 *
 *  @param favoriteId 收藏Id
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)cancelFavorite:(NSString *)favoriteId
                     completion:(void (^)(NSError *error))completion;

/**
 *  获取收藏的视频广场公共资源列表
 *
 *  @param pageIndex  分页当前页码（从0开始）
 *  @param pageSize   分页每页数量（建议20以内）
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)getFavoriteSquareVideoList:(NSInteger)pageIndex
                                   pageSize:(NSInteger)pageSize
                                 completion:(void (^)(NSArray *videoList, NSInteger totalCount, NSError *error))completion;

/**
 *  检查视频广场资源是否被收藏过
 *
 *  @param videoIds   videoIds,可以是多个值
 *  @param completion 回调block
 *
 *  @return operation
 */
+ (NSOperation *)checkFavorite:(NSArray *)videoIds
                    completion:(void (^)(NSArray *checkFavorites, NSError *error))completion;



@end

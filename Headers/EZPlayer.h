//
//  EZPlayer.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/9/16.
//  Copyright (c) 2015年 Hikvision. All rights reserved.
//

#import <UIKit/UIKit.h>

@class EZDeviceRecordFile;
@class EZCloudRecordFile;

/**
 *  预览清晰度
 */
typedef NS_ENUM(NSInteger, EZVideoQuality){
    
    EZVideoQualityLow    = 0,  //流畅
    EZVideoQualityMiddle = 1,  //均衡
    EZVideoQualityHigh   = 2   //高清
};

@protocol EZPlayerDelegate;

@interface EZPlayer : NSObject

@property (nonatomic, weak) id<EZPlayerDelegate> delegate;

/**
 *  根据cameraId构造EZPlayer对象
 *
 *  @param cameraId 摄像头Id
 *
 *  @return EZPlayer对象
 */
+ (instancetype)createPlayerWithCameraId:(NSString *)cameraId;

/**
 *  根据url构造EZPlayer对象 （主要用来处理视频广场的播放）
 *
 *  @param url 播放url
 *
 *  @return EZPlayer对象
 */
+ (instancetype)createPlayerWithUrl:(NSString *)url;

/**
 *  销毁EZPlayer
 *
 *  @return YES/NO;
 */
- (BOOL)destoryPlayer;

/**
 *  设置播放器的view
 *
 *  @param playerView 播放器view
 */
- (void)setPlayerView:(UIView *)playerView;

/**
 *  开始播放
 *
 *  @return YES/NO
 */
- (BOOL)startRealPlay;

/**
 *  停止播放
 *
 *  @return YES/NO
 */
- (BOOL)stopRealPlay;

/**
 *  开启声音
 *
 *  @return YES/NO
 */
- (BOOL)openSound;

/**
 *  关闭声音
 *
 *  @return YES/NO
 */
- (BOOL)closeSound;

/**
 *  开始对讲
 *
 *  @return YES/NO
 */
- (BOOL)startVoiceTalk;

/**
 *  停止对讲
 *
 *  @return YES/NO
 */
- (BOOL)stopVoiceTalk;

/**
 *  开始云存储远程回放
 *  @param cloudFile 云存储文件信息
 *
 *  @return YES/NO
 */
- (BOOL)startPlaybackFromCloud:(EZCloudRecordFile *)cloudFile;

/**
 *  开始远程SD卡回放
 *
 *  @param deviceFile SD卡文件信息
 *
 *  @return YES/NO
 */
- (BOOL)startPlaybackFromDevice:(EZDeviceRecordFile *)deviceFile;

/**
 *  暂停远程回放播放
 */
- (BOOL)pausePlayback;

/**
 *  继续远程回放播放
 */
- (BOOL)resumePlayback;

/**
 *  根据偏移时间播放
 *
 *  @param offsetTime 录像偏移时间
 */
- (void)seekPlayback:(NSDate *)offsetTime;

/**
 *  获取当前播放时间进度
 *
 *  @return 播放进度的NSDate数据
 */
- (NSDate *)getOSDTime;

/**
 *  停止远程回放
 */
- (BOOL)stopPlayback;

/**
 *  设置视频清晰度
 *
 *  @param videoLevel 清晰度 0-流畅，1-均衡，2-高清
 *
 *  @return YES/NO
 */
- (BOOL)setVideoLevel:(EZVideoQuality)videoLevel;

/**
 *  开始本地直播流录像功能
 *
 *  @param recordDataBlock 录像回调数据
 *
 *  @return YES/NO
 */
- (BOOL)startLocalRecord:(void (^)(NSData *data))recordDataBlock;

/**
 *  结束本地直播流录像
 *
 *  @return YES/NO
 */
- (BOOL)stopLocalRecord;

/**
 *  直播画面抓图
 *
 *  @param quality 抓图质量（0～100）,数值越大图片质量越好，图片大小越大
 *
 *  @return image
 */
- (UIImage *)capturePicture:(NSInteger)quality;

@end

@protocol EZPlayerDelegate <NSObject>

/**
 *  播放器播放失败错误回调
 *
 *  @param player 播放器对象
 *  @param error  播放器错误，错误码请对照EZOpenSDKErrorCode使用
 */
- (void)player:(EZPlayer *)player didPlayFailed:(NSError *)error;

/**
 *  播放器消息回调
 *
 *  @param player      播放器对象
 *  @param messageCode 消息码，请对比EZOpenSDKMessageCode使用
 */
- (void)player:(EZPlayer *)player didReceviedMessage:(NSInteger)messageCode;

@end

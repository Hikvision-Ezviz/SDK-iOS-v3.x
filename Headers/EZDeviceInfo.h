//
//  EZDeviceInfo.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/9/16.
//  Copyright (c) 2015年 Hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EZDeviceInfo : NSObject

/**
 *  设备ID（索引）
 */
@property (nonatomic, copy) NSString *deviceId;
/**
 *  设备序列号
 */
@property (nonatomic, copy) NSString *deviceSerial;
/**
 *  设备全序列号
 */
@property (nonatomic, copy) NSString *fullSerial;
/**
 *  设备名称
 */
@property (nonatomic, copy) NSString *deviceName;
/**
 * v3.3版本中该类型发生改变，请注意：
 * IPC设备的含义是--是否开启活动检测，只有0和1；
 * A1设备中含义--是布防状态，0:睡眠 8:在家 16:外出
 */
@property (nonatomic) NSInteger isDefence;
/**
 *  是否开启加密，获取设备列表（getDeviceList接口）获取的对象没有该字段，只有获取单个设备信息的时候才有该字段
 */
@property (nonatomic) BOOL isEncrypt;
/**
 *  设备状态
 */
@property (nonatomic) NSInteger status;
/**
 *  设备图片
 */
@property (nonatomic, copy) NSString *picUrl;
/**
 *  设备类型
 */
@property (nonatomic, copy) NSString *model;
/**
 *  设备版本号
 */
@property (nonatomic, copy) NSString *deviceVersion;
/**
 *  是否支持布撤防
 */
@property (nonatomic, readonly) BOOL isSupportDefence;
/**
 *  是否支持布撤防计划
 */
@property (nonatomic, readonly) BOOL isSupportDefencePlan;
/**
 *  是否支持对讲
 */
@property (nonatomic, readonly) BOOL isSupportTalk;
/**
 *  是否支持云台控制
 */
@property (nonatomic, readonly) BOOL isSupportPTZ;
/**
 *  是否支持放大
 */
@property (nonatomic, readonly) BOOL isSupportZoom;
/**
 *  是否支持升级
 */
@property (nonatomic, readonly) BOOL isSupportUpgrade;
/**
 *  设备能力集协议
 */
@property (nonatomic, copy) NSString *supportExtShort;


@end

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
 *  设备序列号
 */
@property (nonatomic, copy, readonly) NSString *serialNumber;
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
 *  根据cameraId构造设备信息对象
 *
 *  @param cameraId 摄像头ID
 *
 *  @return EZDeviceInfo实例对象
 */
- (instancetype)initWithCameraId:(NSString *)cameraId;

@end

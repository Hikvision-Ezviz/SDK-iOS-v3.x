//
//  EZCameraInfo.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/9/15.
//  Copyright (c) 2015年 Hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EZCameraInfo : NSObject

/**
 *  摄像头ID
 */
@property (nonatomic, copy) NSString *cameraId;
/**
 *  摄像头名称
 */
@property (nonatomic, copy) NSString *cameraName;
/**
 *  通道号
 */
@property (nonatomic) NSInteger channelNo;
/**
 *  设备ID
 */
@property (nonatomic, copy) NSString *deviceId;
/**
 *  设备名称
 */
@property (nonatomic, copy) NSString *deviceName;
/**
 *  设备序列号
 */
@property (nonatomic, copy) NSString *deviceSerial;
/**
 *  设备是否加密
 */
@property (nonatomic) BOOL isEncrypt;
/**
 *  是否是分享设备
 */
@property (nonatomic) NSInteger isShared;
/**
 *  设备PC端设备的封面地址
 */
@property (nonatomic, copy) NSString *picUrl;
/**
 *  设备在线状态
 */
@property (nonatomic) BOOL isOnline;
/**
 *  是否开启活动检测
 */
@property (nonatomic) BOOL isDefence;

@end

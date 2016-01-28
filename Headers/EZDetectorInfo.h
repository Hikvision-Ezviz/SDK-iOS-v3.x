//
//  EZDetectorInfo.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 16/1/12.
//  Copyright © 2016年 Hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EZDetectorInfo : NSObject

/**
 *  探测器序列号
 */
@property (nonatomic, copy) NSString *detectorSerial;
/**
 *  探测器类型
 */
@property (nonatomic, copy) NSString *type;
/**
 *  探测器名称
 */
@property (nonatomic, copy) NSString *typeName;
/**
 *  防区故障状态，0恢复，1产生
 */
@property (nonatomic) NSInteger faultZoneStatus;
/**
 *  电池欠压状态，0恢复，1产生
 */
@property (nonatomic) NSInteger underVoltageStatus;
/**
 *  无线干扰状态，0恢复，1产生
 */
@property (nonatomic) NSInteger wirelessInterferenceStatus;
/**
 *  设备离线状态，0恢复，1产生
 */
@property (nonatomic) NSInteger offlineStatus;

@end

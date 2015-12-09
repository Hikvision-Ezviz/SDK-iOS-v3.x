//
//  EZDeviceRecordFile.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/9/17.
//  Copyright (c) 2015年 Hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EZDeviceRecordFile : NSObject

/**
 *  远程SD卡录像文件开始时间
 */
@property (nonatomic, strong) NSDate *startTime;
/**
 *  远程SD卡录像文件结束时间 
 */
@property (nonatomic, strong) NSDate *stopTime;

@end

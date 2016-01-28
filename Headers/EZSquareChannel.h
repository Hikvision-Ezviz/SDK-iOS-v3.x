//
//  EZSquareCategory.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/11/24.
//  Copyright © 2015年 Hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EZSquareChannel : NSObject

/**
 *  频道编号
 */
@property (nonatomic) NSInteger id;
/**
 *  频道等级
 */
@property (nonatomic) NSInteger level;
/**
 *  频道名称
 */
@property (nonatomic, copy) NSString *name;

@end

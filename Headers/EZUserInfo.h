//
//  EZUserInfo.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/12/11.
//  Copyright © 2015年 Hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EZUserInfo : NSObject

/**
 *  用户名
 */
@property (nonatomic, copy) NSString *username;
/**
 *  昵称
 */
@property (nonatomic, copy) NSString *nickname;
/**
 *  用户头像地址
 */
@property (nonatomic, copy) NSString *avatarUrl;

@end

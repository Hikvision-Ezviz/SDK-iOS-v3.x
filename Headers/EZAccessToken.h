//
//  EZAccessToken.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/10/19.
//  Copyright © 2015年 Hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EZAccessToken : NSObject

/**
 *  accessToken 登录凭证
 */
@property (nonatomic, copy) NSString *accessToken;
/**
 *  accessToekn的过期秒数，用当前时间加上expire的秒数为过期时间
 */
@property (nonatomic, assign) NSInteger expire;

@end

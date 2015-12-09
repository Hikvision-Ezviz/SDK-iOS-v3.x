//
//  EZCheckFavoriteSquareVideo.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/12/2.
//  Copyright © 2015年 Hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EZCheckFavoriteSquareVideo : NSObject

/**
 *  视频编号
 */
@property (nonatomic, copy) NSString *videoId;
/**
 *  收藏编号
 */
@property (nonatomic, copy) NSString *favoriteId;

@end

//
//  EZFavoriteSquareVideo.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/11/25.
//  Copyright © 2015年 Hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EZFavoriteSquareVideo : NSObject

/**
 *  视频编号
 */
@property (nonatomic, copy) NSString *id;
/**
 *  视频标题
 */
@property (nonatomic, copy) NSString *title;
/**
 *  视频播放url
 */
@property (nonatomic, copy) NSString *playUrl;
/**
 *  视频封面
 */
@property (nonatomic, copy) NSString *coverUrl;
/**
 *  视频地址
 */
@property (nonatomic, copy) NSString *address;
/**
 *  纬度
 */
@property (nonatomic) double latitude;
/**
 *  经度
 */
@property (nonatomic) double longitude;
/**
 *  视频被喜欢次数
 */
@property (nonatomic) NSInteger likeCount;
/**
 *  视频被收藏次数
 */
@property (nonatomic) NSInteger favoriteCount;
/**
 *  视频被评论次数
 */
@property (nonatomic) NSInteger commentCount;
/**
 *  视频被预览次数
 */
@property (nonatomic) NSInteger viewedCount;
/**
 *  收藏ID
 */
@property (nonatomic, copy) NSString *favoriteId;
/**
 *  收藏时间
 */
@property (nonatomic, strong) NSDate *favoriteTime;

@end

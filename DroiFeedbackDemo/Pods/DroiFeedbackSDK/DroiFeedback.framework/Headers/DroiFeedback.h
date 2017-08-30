//
//  DroiFeedback.h
//  DroiFeedbackDemo
//
//  Created by Jon on 16/6/27.
//  Copyright © 2016年 Droi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class DroiError;

typedef NS_ENUM(NSInteger, DroiFeedbackNavigationBarStyle) {
    DroiFeedbackNavigationBarStyleDefault,
    DroiFeedbackNavigationBarStyleBlack,
};

@interface DroiFeedback : NSObject


/**初始化 SDK
 @param APIKey 在 DroiBaaS 官网上面申请的 SDK 对应的 APIKey
 */
+ (BOOL)initializeWithAPIKey:(NSString *)APIKey;

/**调用默认反馈页面
 @param viewController 需要调用反馈页面的ViewController
 */
+ (void)callFeedbackWithViewController:(UIViewController *)viewController;

/**设置UserId
 @param userId 填入自定义的UserId 如果使用了DroiUser账号体系,则不需要填写,默认为已登录账号的UserId
 */
+ (void)setUserId:(NSString *)userId;

/**设置色调
 */
+ (void)setColor:(UIColor *)color;

/**
 设置反馈页面 navigationBar 色调
 @param style default 为 浅色
 */
+ (void)setNavigationBarStyle:(DroiFeedbackNavigationBarStyle)style;

/**获取当前的UserId
 */
+ (NSString *)getCurrentUserId;

/**获取 SDK 版本号
 */
+ (NSString *)getVersion;
@end

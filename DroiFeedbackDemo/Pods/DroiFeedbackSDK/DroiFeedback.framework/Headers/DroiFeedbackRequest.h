//
//  DroiFeedbackRequest.h
//  DroiFeedbackDemo
//
//  Created by Jon on 16/6/28.
//  Copyright © 2016年 Droi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DroiCoreSDK/DroiCoreSDK.h>

@interface DroiFeedbackRequest : NSObject

/**获取反馈内容列表
 @param error 错误信息
 @return 反馈内容列表  DroiFeedbackModel 数组
 */
+ (NSArray *)requestToGetFeedbackList:(DroiError**) error;

/**获取反馈内容列表
 @param callback 回调 block
 */
+ (void)requestGetFeedbackList:(void(^)(NSArray *result, DroiError *error))callback;

/**提交反馈内容
 @param feedbackString 反馈内容
 @param contact 联系方式
 @param imageArray  UIImage 格式图片数组
 @param error 错误信息
 @return 返回结果
 */
+ (BOOL)requestToSummitFeedback:(NSString *)feedbackString contact:(NSString *)contact imageArray:(NSArray <UIImage *>*)imageArray error:(DroiError**) error;

/**提交反馈内容
 @param feedbackString 反馈内容
 @param contact 联系方式
 @param imageArray  UIImage 格式图片数组
 @param callback  回调 block
 */
+ (void)requestToSummitFeedback:(NSString *)feedbackString contact:(NSString *)contact imageArray:(NSArray <UIImage *>*)imageArray callback:(void(^)(BOOL result,DroiError *error))callback;

@end


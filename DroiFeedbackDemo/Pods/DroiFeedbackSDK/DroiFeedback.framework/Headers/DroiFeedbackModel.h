//
//  DroiFeedbackModel.h
//  DroiFeedbackDemo
//
//  Created by Jon on 16/6/28.
//  Copyright © 2016年 Droi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DroiFeedbackModel : NSObject


@property (copy, nonatomic)NSString *content;   //反馈内容

@property (copy, nonatomic)NSString *createTime;//创建时间

@property (copy, nonatomic)NSString *reply;     //回复内容

@property (copy, nonatomic)NSString *replyTime; //回复时间

@property (strong, nonatomic)NSMutableArray *imageList;//图片 url 列表,string数组
@property (strong, nonatomic)NSArray *objList;//objId 数组 ，根据objId去查询对应的图片 url。
@end

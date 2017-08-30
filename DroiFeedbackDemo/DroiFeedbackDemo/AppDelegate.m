//
//  AppDelegate.m
//  DroiFeedbackDemo
//
//  Created by liaojun on 16/7/25.
//  Copyright © 2016年 Droi. All rights reserved.
//

#import "AppDelegate.h"
#import "FeedbackViewController.h"
#import <DroiCoreSDK/DroiCoreSDK.h>
#import <DroiFeedback/DroiFeedback.h>
//请替换成从 DroiBaaS 官网申请的 反馈 ApiKey 同时info.plist中的DROI_APP_ID要修改
#define DROI_FEEDBACK_API_KEY @"KxVGJsQoLz0uVsGIUXd6ZRYvKKB7UT9BVPFpaUJjOAKsYTSmMZFC35i8VURf7DWu"
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    [DroiCore initializeCore];
    [DroiFeedback initializeWithAPIKey:DROI_FEEDBACK_API_KEY];
    FeedbackViewController *feedbackVC = [[FeedbackViewController alloc] init];
    self.window.rootViewController = feedbackVC;
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end

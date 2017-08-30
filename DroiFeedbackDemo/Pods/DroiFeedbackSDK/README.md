
# 用户反馈

## 简介
用户反馈可以帮助开发者在应用内收集用户问题反馈和意见建议，开发者可以及时回复用户的反馈，加强与用户之间的沟通，及时了解用户的需求，有利于提升产品质量。

## 安装
### 快速入门
由于DroiFeedback SDK依赖于DroiCore SDK，所以请在安装DroiFeedback SDK之前仔细阅读[快速入门](http://www.droibaas.com/Index/docFile/mark_id/24137.html) ，完成DroiCore SDK的安装。

### 使用CocoaPods方式集成（推荐）
DroiFeedback SDK使用CocoaPods作为函数库的管理工具。我们推荐您使用CocoaPods这种方式来安装SDK，这样可以简化安装DroiFeedback SDK的流程。如果您未安装CocoaPods，请参考[《CocoaPods安装和使用教程》](http://www.jianshu.com/p/b7bbf7f6af54)完成安装。CocoaPods安装完成后，请在项目根目录下创建一个Podfile文件，并添加如下内容（如果已有直接添加即可）：

```
pod 'DroiCoreSDK'
post_install do |installer|
require './Pods/DroiCoreSDK/scripts/postInstall.rb'
DroiCoreParser.installParser()
end
pod  'DroiFeedbackSDK'
```
由于DroiFeedback SDK需依赖于DroiCore SDK，以上命令会安装DroiCore SDK并安装DroiFeedback SDK。如果之前已经安装过DroiCore SDK只需要添加

```
pod  'DroiFeedbackSDK'
```
之后在控制台中cd到Podfile文件所在目录，执行如下命令完成安装。

```
pod  install
```

###  手动集成
将SDK包解压，在XCode中选择”Add files to 'Your project name'…”，将解压后的`DroiFeedback.framework`和`DroiFeedbackBundle.bundle`添加到你的工程目录中。

## 使用
### 初始化 SDK
在使用DroiFeedback SDK之前需要先初始化DroiFeedback SDK 请在Applegate.m中添加如下代码，完成初始化。
> **注意：** 由于api服务的升级，现在使用用户反馈必须要设置`ApiKey`，首先在`web控制台`->`应用管理中心`->`设置详情`->`安全设置`中打开用户反馈服务，然后`ApiKey`可以从`web控制台`->`应用管理中心`->`应用设置`->`安全密钥`中获取。

```
//请替换成从 DroiBaaS 官网申请的 反馈 ApiKey 同时info.plist的DROI_APP_ID要修改
#define DROI_FEEDBACK_API_KEY @"w4D6-2Bn3q17gDPwpeVragSKVHIVwRK0yhjlflNMG-pp6JhfU72GW2sOw_dfIbL7"

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [DroiCore initializeCore];
    //使用 ApiKey 初始化 DroiFeedbackSDK 必须执行
    [DroiFeedback initializeWithAPIKey:DROI_FEEDBACK_API_KEY];
    return YES;
}
```
### 调用反馈页面  
在适合的页面调用接口后，会自动跳转到反馈页面，默认情况下开发者不需要任何额外设置

``` 
[DroiFeedback callFeedbackWithViewController:self];

```
### 设置 userId

```
[DroiFeedback setUserId:userId];
```
***注意***

* userId用于标识用户，您可以传入您自有账号系统的用户唯一标识，该接口保证用户在其他设备上登录时同样能够获取到该用户对应的反馈。请确保每次调用callFeedback接口之前，调用该接口。
* 如果您使用了DroiCore SDK中的DroiUser账号系统，无需手动调用该接口，反馈SDK会自动添加。  
* 如果您没有设置userId，会使用DroiCore SDK中DroiUser的匿名userId。

## 自定义色调
DroiFeedback SDK提供了对整体UI色调自定义的功能，开发者可以调用以下接口，实现对整体UI色调的自定义

```
[DroiFeedback setColor:[UIColor greenColor]];
```

### 后台页面
在后台页面可以查看用户反馈量、今日回复量和总反馈量。  
在反馈列表中，可以选中一条反馈进行回复。回复后，反馈用户可以在反馈回复页面看到回复。  

![](http://www.droibaas.com/Uploads/DocFile/579971a268030.png)

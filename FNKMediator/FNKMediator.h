//
//  FNKMediator.h
//  FNKRuntimeKit
//
//  Created by FranK on 2019/1/10.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@protocol FNKMediatorUrlFilterProtocol <NSObject>
@required
- (BOOL)isCanOpenURL:(nonnull NSString *)urlStr;
@end

@class FNKMediatorAppdelegateArguments;
@interface FNKMediator : NSObject


@property(weak, nonatomic) id<FNKMediatorUrlFilterProtocol> urlFilterDelegate;
+ (nonnull instancetype)sharedInstance;
/*
NSError *error;
[[FNKMediator sharedInstance] nativePerformTarget:@"ViewController" action:@"toGetPaser:" params:@{@"FNK":@"hello"} completion:^(NSDictionary * _Nonnull result) {
    NSLog(@"调用了成功回调");
} failure:^(NSError * _Nonnull error) {
    NSLog(@"调用了失败回调");
} error:&error];
 - (void)toGetPaser:(FNKMediatorArgument*)arg{
 
 }
 */

/**
 第三方，以及外界app通过url调用
 调用这个api,只会给方法的第一个参数传智,接收的参数类型在运行时是FNKMediatorArgument
 */
- (nullable id)thirdPartyPerformActionWithUrl:(nonnull NSString *)urlStr
                                   completion:(nullable void (^)(NSDictionary<NSString *, id> *result))completion;

/**
 本地url调用，不推荐，内部可以解析url以及参数，推荐内部调用使用下面的利用字符串调用
 调用这个api,只会给方法的第一个参数传智,接收的参数类型在运行时是FNKMediatorArgument
 */
- (nullable id)nativePerformActionWithUrl:(nonnull NSString *)urlStr
                                      arg:(nullable NSDictionary<NSString *, id> *)arg
                               completion:(nullable void (^)(NSDictionary<NSString *, id> *result))completionCallBack
                                  failure:(nullable void (^)(NSError *error))failureCallBack;

/**
 本地利用字符串调用，推荐，内部也做了处理
 调用这个api,只会给方法的第一个参数传智,接收的参数类型在运行时是FNKMediatorArgument
 */
- (nullable id)nativePerformTarget:(nonnull NSString *)targetName
                            action:(nonnull NSString *)actionName
                            params:(nullable NSDictionary<NSString *, id> *)params
                        completion:(nullable void (^)(NSDictionary<NSString *, id> *result))completionCallBack
                           failure:(nullable void (^)(NSError *error))failureCallBack;

/**
 根据字符串动态调用各个模块的appdelegate方法
 支持多参数,这里的参数只做转发不校验
 */
- (nullable id)performAppDelegateTarget:(nonnull NSString *)targetName
                             actionName:(nonnull NSString *)actionName
                                 params:(nonnull FNKMediatorAppdelegateArguments *)paramsObj;

/**
 直接向这个对象动态调用appdelegate的方法
 支持多参数,这里的参数只做转发不校验
 */
- (nullable id)performAppDelegateTargetObject:(nonnull id)targetObj
                                   actionName:(nonnull NSString *)actionName
                                       params:(nonnull FNKMediatorAppdelegateArguments *)paramsObj;

#pragma mark - 异常处理
/**
 第三方，以及外界app通过url调用,包含了error处理
 调用这个api,只会给方法的第一个参数传智,接收的参数类型在运行时是FNKMediatorArgument
 */
- (nullable id)thirdPartyPerformActionWithUrl:(nonnull NSString *)urlStr
                                   completion:(nullable void (^)(NSDictionary<NSString *, id> *result))completion
                                        error:(NSError * __autoreleasing *)error;

/**
 本地url调用，不推荐，内部可以解析url以及参数，推荐内部调用使用下面的利用字符串调用,包含了error处理
 调用这个api,只会给方法的第一个参数传智,接收的参数类型在运行时是FNKMediatorArgument
 */
- (nullable id)nativePerformActionWithUrl:(nonnull NSString *)urlStr
                                      arg:(nullable NSDictionary<NSString *, id> *)arg
                               completion:(nullable void (^)(NSDictionary<NSString *, id> *result))completionCallBack
                                  failure:(nullable void (^)(NSError *error))failureCallBack
                                    error:(NSError * __autoreleasing *)error;

/**
 本地利用字符串调用，推荐，内部也做了处理,包含了error处理
 调用这个api,只会给方法的第一个参数传智,接收的参数类型在运行时是FNKMediatorArgument
 */
- (nullable id)nativePerformTarget:(nonnull NSString *)targetName
                            action:(nonnull NSString *)actionName
                            params:(nullable NSDictionary<NSString *, id> *)params
                        completion:(nullable void (^)(NSDictionary<NSString *, id> *result))completionCallBack
                           failure:(nullable void (^)(NSError *error))failureCallBack
                             error:(NSError * __autoreleasing *)error;

/**
 本地利用字符串调用，推荐，内部也做了处理,包含了error处理,主要是提供给swift使用的,因为swift不支持**error
 调用这个api,只会给方法的第一个参数传智,接收的参数类型在运行时是FNKMediatorArgument
 */
- (nullable id)nativePerformTarget:(nonnull NSString *)targetName
                            action:(nonnull NSString *)actionName
                            params:(nullable NSDictionary<NSString *, id> *)params
                        completion:(nullable void (^)(NSDictionary<NSString *, id> *result))completionCallBack
                           failure:(nullable void (^)(NSError *error))failureCallBack
                  invokeErrorBlock:(nullable void (^)(NSError *error))invokeErrorBlock;

/**
 根据字符串动态调用各个模块的appdelegate方法,包含了error处理
 支持多参数,这里的参数只做转发不校验
 */
- (nullable id)performAppDelegateTarget:(nonnull NSString *)targetName
                             actionName:(nonnull NSString *)actionName
                                 params:(nonnull FNKMediatorAppdelegateArguments *)paramsObj
                                  error:(NSError **)error;

/**
 直接向这个对象动态调用appdelegate的方法,包含了error处理
 支持多参数,这里的参数只做转发不校验
 */
- (nullable id)performAppDelegateTargetObject:(nonnull id)targetObj
                                   actionName:(nonnull NSString *)actionName
                                       params:(nonnull FNKMediatorAppdelegateArguments *)paramsObj
                                        error:(NSError **)error;
@end

NS_ASSUME_NONNULL_END

//
//  FNKMediatorError.h
//  Pods-FNKRuntimeKit_Example
//
//  Created by FranK on 2019/1/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const kFNKMediatorErrorDomain;
FOUNDATION_EXPORT NSString *const kFNKMediatorErrorInfoKey;

//参数错误
FOUNDATION_EXPORT NSUInteger const kFNKMediatorErrorParmsCode;
FOUNDATION_EXPORT NSString *const kFNKMediatorErrorParmsInfo;

//URL参数解析错误
FOUNDATION_EXPORT NSUInteger const kFNKMediatorErrorURLParameterAnalysisCode;
FOUNDATION_EXPORT NSString *const kFNKMediatorErrorURLParameterAnalysisInfo;

//不包含组件
FOUNDATION_EXPORT NSUInteger const kFNKMediatorErrorUndefindTargetCode;
FOUNDATION_EXPORT NSString *const kFNKMediatorErrorUndefindTargetInfo;

//找不到sel
FOUNDATION_EXPORT NSUInteger const kFNKMediatorErrorUndefindSelctorCode;
FOUNDATION_EXPORT NSString *const kFNKMediatorErrorUndefindSelctorInfo;

//函数签名异常
FOUNDATION_EXPORT NSUInteger const kFNKMediatorErrorUndefindMethodSignatureCode;
FOUNDATION_EXPORT NSString *const kFNKMediatorErrorUndefindMethodSignatureInfo;

//runtime派发参数数量异常
FOUNDATION_EXPORT NSUInteger const kFNKMediatorErrorRuntimeParamsCode;
FOUNDATION_EXPORT NSString *const kFNKMediatorErrorRuntimeParamsInfo;

//非Appdelegate方法调用
FOUNDATION_EXPORT NSUInteger const kFNKMediatorErrorAppdelegateRuntimeInvokeCode;
FOUNDATION_EXPORT NSString *const kFNKMediatorErrorAppdelegateRuntimeInvokeInfo;

//无法匹配返回值类型
FOUNDATION_EXPORT NSUInteger const kFNKMediatorErrorUndefindReturnTypeCode;
FOUNDATION_EXPORT NSString *const kFNKMediatorErrorUndefindReturnTypeInfo;

//该URL无权限访问
FOUNDATION_EXPORT NSUInteger const kFNKMediatorErrorURLNotAllowedCode;
FOUNDATION_EXPORT NSString *const kFNKMediatorErrorURLNotAllowedInfo;

NS_ASSUME_NONNULL_END

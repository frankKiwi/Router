//
//  FNKMediatorError.m
//  Pods-FNKRuntimeKit_Example
//
//  Created by FranK on 2019/1/11.
//

#import "FNKMediatorError.h"

NSString *const kFNKMediatorErrorDomain = @"com.FNKRuntimeKit.FNKMediator";
NSString *const kFNKMediatorErrorInfoKey = @"kFNKMediatorErrorInfoKey";

NSUInteger const kFNKMediatorErrorParmsCode = 7800;
NSString *const kFNKMediatorErrorParmsInfo = @"参数错误";

NSUInteger const kFNKMediatorErrorURLParameterAnalysisCode = 7801;
NSString *const kFNKMediatorErrorURLParameterAnalysisInfo = @"URL参数错误";

NSUInteger const kFNKMediatorErrorUndefindTargetCode = 7802;
NSString *const kFNKMediatorErrorUndefindTargetInfo = @"组件没找到";

NSUInteger const kFNKMediatorErrorUndefindSelctorCode = 7803;
NSString *const kFNKMediatorErrorUndefindSelctorInfo = @"SEL没有被实现或传入为空";

NSUInteger const kFNKMediatorErrorUndefindMethodSignatureCode = 7804;
NSString *const kFNKMediatorErrorUndefindMethodSignatureInfo = @"函数签名异常";

NSUInteger const kFNKMediatorErrorRuntimeParamsCode = 7805;
NSString *const kFNKMediatorErrorRuntimeParamsInfo = @"runtime参数传入数量异常";

NSUInteger const kFNKMediatorErrorAppdelegateRuntimeInvokeCode = 7806;
NSString *const kFNKMediatorErrorAppdelegateRuntimeInvokeInfo = @"Runtime调用的不是appdelegate方法";

NSUInteger const kFNKMediatorErrorUndefindReturnTypeCode = 7807;
NSString *const kFNKMediatorErrorUndefindReturnTypeInfo = @"返回值类型无法匹配";

NSUInteger const kFNKMediatorErrorURLNotAllowedCode = 7808;
NSString *const kFNKMediatorErrorURLNotAllowedInfo = @"该URL无权限访问app内部";

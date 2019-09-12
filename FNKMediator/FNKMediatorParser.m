//
//  FNKMediaorParser.m
//  Expecta
//
//  Created by FranK on 2019/1/10.
//

#import "FNKMediatorParser.h"

NSString* const kFNKMediatorENCodeURL      = @"__FNKMediatorENCodeURL";
NSString* const kFNKMediatorScheme         = @"__FNKMediatorScheme";
NSString* const kFNKMediatorModule         = @"__FNKMediatorModule";
NSString* const kFNKMediatorAction         = @"__FNKMediatorAction";
NSString* const kFNKMediatorQuery          = @"__FNKMediatorQuery";
NSString* const kFNKMediatorSymbol         = @"__FNKMediatorSymbol";
NSString* const kFNKMediatorErrorKey       = @"__FNKMediatorErrorKey";

@implementation FNKMediatorParser

/**
 从url获取参数,NSDict->NSMutableDict
 */
- (NSMutableDictionary *)extractParametersFromURL:(NSString *)url{
    //解析url获取组件
    NSDictionary* pathComponents = [self getComponentsFromURL:url];
    NSMutableDictionary* parameters = [NSMutableDictionary dictionary];
    if (pathComponents) {
        [parameters addEntriesFromDictionary:pathComponents];
    }
    
    return parameters;
}

/**
 解析url获取组件
 */
- (NSDictionary *)getComponentsFromURL:(NSString*)url{
    
    //参数
    NSMutableDictionary *coms = [NSMutableDictionary dictionary];
    
    NSURL *nsUrl = [NSURL URLWithString:url];
    
    //无法解析直接抛出异常
    if (!nsUrl) {
        coms[kFNKMediatorErrorKey] = @(YES);
        return coms;
    }
    
    //scheme://module/action
    NSString *scheme = [nsUrl scheme];
    NSString *module = [nsUrl host];
    NSString *action = [[nsUrl path] stringByReplacingOccurrencesOfString:@"/" withString:@"_"];
    if (action && [action length] && [action hasPrefix:@"_"]) {
        action = [action stringByReplacingCharactersInRange:NSMakeRange(0,1) withString:@""];
    }
    
    NSString *query = nil;
    //字符串截取数组
    NSArray* pathInfo = [nsUrl.absoluteString componentsSeparatedByString:@"?"];
    if (pathInfo.count > 1) {
        //0元素是前面的url 1元素是参数
        query = [pathInfo objectAtIndex:1];
    }
    
    if ( nsUrl ) {
        //完整url
        coms[kFNKMediatorENCodeURL] = nsUrl.absoluteString;
    }
    if ( scheme && [scheme length] ) {
        //router
        coms[kFNKMediatorScheme] = scheme;
    }
    if ( module && [module length] ) {
        //target 类
        coms[kFNKMediatorModule] = module;
    }
    if ( action && [action length] ) {
        //方法
        coms[kFNKMediatorAction] = action;
    }
    if ( query && [query length] ) {
        //参数
        coms[kFNKMediatorQuery] = query;
    }
    
    //象征 module_action
    NSString *symbol = [NSString stringWithFormat:@"%@_%@", module, action];
    coms[kFNKMediatorSymbol] = symbol;
    coms[kFNKMediatorErrorKey] = @(NO);
    
    return coms;
}

/**
 提取参数
 */
- (NSDictionary *)extractParamsFromQuery:(NSString *)query{
    
    if (query == nil) {
        return nil;
    }
    
    NSMutableDictionary *parameters = nil;
    NSString *parametersString = query;
    NSArray *paramStringArr = [parametersString componentsSeparatedByString:@"&"];
    if (paramStringArr && [paramStringArr count]>0) {
        parameters = [NSMutableDictionary dictionary];
        for (NSString* paramString in paramStringArr) {
            NSArray *paramArr = [paramString componentsSeparatedByString:@"="];
            if (paramArr.count > 1) {
                NSString *key = [paramArr objectAtIndex:0];
                NSString *value = [paramArr objectAtIndex:1];
                parameters[key] = [value stringByRemovingPercentEncoding];
            }
        }
    }
    return parameters;
}

// url Query 与方法中传参组合
- (NSMutableDictionary *) composeParams:(NSDictionary *)queryParams attachParams:(id)attachParams {
    if (!queryParams && !attachParams) return nil;
    
    NSMutableDictionary *resultParams = [NSMutableDictionary dictionary];
    if (queryParams && [queryParams isKindOfClass:[NSDictionary class]]) {
        [resultParams addEntriesFromDictionary:queryParams];
    }
    if (attachParams && [attachParams isKindOfClass:[NSDictionary class]]) {
        [resultParams addEntriesFromDictionary:attachParams];
    }
    
    return resultParams;
}

@end

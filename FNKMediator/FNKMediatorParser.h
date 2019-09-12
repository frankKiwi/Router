//
//  FNKMediaorParser.h
//  Expecta
//
//  Created by FranK on 2019/1/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern  NSString *const __nonnull kFNKMediatorENCodeURL;
extern  NSString *const __nonnull kFNKMediatorScheme;
extern  NSString *const __nonnull kFNKMediatorModule;
extern  NSString *const __nonnull kFNKMediatorAction;
extern  NSString *const __nonnull kFNKMediatorQuery;
extern  NSString *const __nonnull kFNKMediatorSymbol;
extern  NSString *const __nonnull kFNKMediatorErrorKey;

@interface FNKMediatorParser : NSObject

- (NSMutableDictionary *)extractParametersFromURL:(NSString *)url;
- (NSDictionary *)extractParamsFromQuery:(NSString *)query;
- (NSMutableDictionary *) composeParams:(NSDictionary *)queryParams attachParams:(id)attachParams;

@end

NS_ASSUME_NONNULL_END

//
//  FNKMediatorAppdelegateArguments.h
//  FNKRuntimeKit
//
//  Created by Link on 2019/1/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FNKMediatorAppdelegateArguments : NSObject

- (instancetype)addElement:(nullable id)element;
- (NSArray *)getArgumentsArray;
@end

NS_ASSUME_NONNULL_END

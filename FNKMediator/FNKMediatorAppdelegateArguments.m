//
//  FNKMediatorAppdelegateArguments.m
//  FNKRuntimeKit
//
//  Created by Link on 2019/1/13.
//

#import "FNKMediatorAppdelegateArguments.h"

@interface FNKMediatorAppdelegateArguments()
@property (strong, nonatomic)NSMutableArray *mArray;
@end
@implementation FNKMediatorAppdelegateArguments

- (instancetype)addElement:(nullable id)element {
    
    if (element) {
        [self.mArray addObject:element];
    } else {
        [self.mArray addObject:[NSNull null]];
    }
    return self;
}
- (NSArray *)getArgumentsArray {
    return [self.mArray copy];
}
- (NSMutableArray *)mArray {
    if (!_mArray) {
        _mArray = [NSMutableArray array];
    }
    return _mArray;
}
@end

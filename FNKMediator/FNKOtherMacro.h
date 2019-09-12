//
//  FNKOtherMacro.m
//  FNKRuntimeKit
//
//  Created by FranK on 2019/1/10.
//

#ifdef DEBUG
#define FNKLog(...) NSLog(__VA_ARGS__);\
NSLog(@"file===%@, line===%d",[[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__)
#else
#define FNKLog(...)
#endif


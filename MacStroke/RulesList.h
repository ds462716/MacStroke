//
// Created by codefalling on 15/10/17.
// Copyright (c) 2015 Chivalry Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MASShortcut;

@interface RulesList : NSObject{
    //NSMutableArray *points;
    NSInteger ruleIndex;
}
typedef enum {
    FILTER_TYPE_WILDCARD, // for example *chrome
    FILTER_TYPE_REGEX
} FilterType;

typedef enum {
    ACTION_TYPE_SHORTCUT,
    ACTION_TYPE_APPLE_SCRIPT,
    ACTION_TYPE_TEXT,
    ACTION_TYPE_PASSWORD,
} ActionType;


- (void)addRuleWithDirection:(NSString *)direction
                 gestureData:(NSMutableArray*)gestureData
                      filter:(NSString *)filter
                  filterType:(FilterType)filterType
                  actionType:(ActionType)actionType
             shortcutKeyCode:(NSUInteger)shortcutKeyCode // when actionType == ACTION_TYPE_SHORTCUT required,or 0
                shortcutFlag:(NSUInteger)shortcutFlag // when actionType == ACTION_TYPE_SHORTCUT required,or 0
                 appleScriptId:(NSString *)appleScriptId // when actionType == ACTION_TYPE_APPLE_SCRIPT required,or nil
                        text:(NSString*)text
                    password:(NSString*)password
                        note:(NSString *)note;

- (void)setActionTypeWithActionType:(ActionType)actonType
                            atIndex:(NSUInteger)index;

- (void)removeRuleAtIndex:(NSInteger)index;

- (NSInteger)count;

- (NSString *)directionAtIndex:(NSUInteger)index;

- (NSString *)filterAtIndex:(NSUInteger)index;

- (FilterType)filterTypeAtIndex:(NSUInteger)index;

- (ActionType)actionTypeAtIndex:(NSUInteger)index;

- (NSString *)noteAtIndex:(NSUInteger)index;

- (NSString *)appleScriptIdAtIndex:(NSUInteger)index;

- (NSUInteger)shortcutKeycodeAtIndex:(NSUInteger)index;

- (NSUInteger)shortcutFlagAtIndex:(NSUInteger)index;

- (NSString *)dataAtIndex:(NSUInteger)index;

- (BOOL)triggerOnEveryMatchAtIndex:(NSUInteger)index;

- (void)setShortcutWithKeycode:(NSUInteger)keycode withFlag:(NSUInteger)flag atIndex:(NSUInteger)index;

- (void)setWildFilter:(NSString *)filter atIndex:(NSUInteger)index;

- (void)setDirection:(NSString *)direction atIndex:(NSUInteger)index;

- (void)setAppleScriptId:(NSString *)id atIndex:(NSUInteger)index;

- (void)setNote:(NSString *)note atIndex:(NSUInteger)index;

- (NSString *)textAtIndex:(NSUInteger)index;

- (NSString *)passwordAtIndex:(NSUInteger)index;

- (void)setPassword:(NSString *)password atIndex:(NSUInteger)index;

- (void)setText:(NSString *)text atIndex:(NSUInteger)index;

- (void)setTriggerOnEveryMatch:(BOOL)match atIndex:(NSUInteger)index;

- (void)setGestureData:(NSMutableArray*) data atIndex:(NSUInteger)index;

- (bool)handleGesture:(NSInteger)Index isLastGesture:(BOOL)last;

- (NSInteger)suitedRuleWithGesture:(NSString *)gesture;

- (BOOL)appSuitedRule:(NSString*)bundleId;

- (void)reInit;

- (void)clear;

- (void)save;

- (NSData *)nsData;

- (BOOL)matchFilter:(NSString *)text atIndex:(NSUInteger)index;

- (RulesList *)initWithNsData:(NSData *)data;

+ (RulesList *)sharedRulesList;


+(void)pressKeyWithFlags:(CGEventFlags)flags virtualKey:(CGKeyCode)virtualKey;

@end

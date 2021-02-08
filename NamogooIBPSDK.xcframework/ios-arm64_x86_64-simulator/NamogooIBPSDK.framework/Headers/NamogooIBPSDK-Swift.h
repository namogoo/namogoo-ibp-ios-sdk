#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.3.2 (swiftlang-1200.0.45 clang-1200.0.32.28)
#ifndef NAMOGOOIBPSDK_SWIFT_H
#define NAMOGOOIBPSDK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreData;
@import Foundation;
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="NamogooIBPSDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class NSEntityDescription;
@class NSManagedObjectContext;

SWIFT_CLASS_NAMED("Cart")
@interface Cart : NSManagedObject
- (nonnull instancetype)initWithEntity:(NSEntityDescription * _Nonnull)entity insertIntoManagedObjectContext:(NSManagedObjectContext * _Nullable)context OBJC_DESIGNATED_INITIALIZER;
@end


@interface Cart (SWIFT_EXTENSION(NamogooIBPSDK))
@property (nonatomic, copy) NSDate * _Nullable date;
@property (nonatomic, copy) NSString * _Nullable sessionId;
@property (nonatomic) double subtotal;
@property (nonatomic) double subtotalInDefault;
@property (nonatomic) double total;
@property (nonatomic) double totalInDefault;
@end


SWIFT_CLASS_NAMED("Event")
@interface Event : NSManagedObject
- (nonnull instancetype)initWithEntity:(NSEntityDescription * _Nonnull)entity insertIntoManagedObjectContext:(NSManagedObjectContext * _Nullable)context OBJC_DESIGNATED_INITIALIZER;
@end


@interface Event (SWIFT_EXTENSION(NamogooIBPSDK))
@property (nonatomic, copy) NSString * _Nullable id;
@property (nonatomic) BOOL sent;
@property (nonatomic, copy) NSString * _Nullable sessionid;
@property (nonatomic) double time;
@property (nonatomic, copy) NSString * _Nullable type;
@property (nonatomic, copy) NSData * _Nullable value;
@end

typedef SWIFT_ENUM(NSInteger, EventParamConsts, open) {
  EventParamConstsRuleName = 0,
  EventParamConstsViewController = 1,
  EventParamConstsVendorEventType = 2,
};


SWIFT_CLASS("_TtC13NamogooIBPSDK19EventParamConverter")
@interface EventParamConverter : NSObject
+ (NSString * _Nonnull)paramName:(enum EventParamConsts)event SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, EventType, open) {
  EventTypeComponentInit = 0,
  EventTypeComponentForeground = 1,
  EventTypeComponentBackground = 2,
  EventTypeComponentRemovedFromVisualHeirarchy = 3,
  EventTypeComponentAddedToVisualHeirarchy = 4,
  EventTypeAppActive = 5,
  EventTypeAppBackground = 6,
  EventTypeAppForeground = 7,
  EventTypeAppInit = 8,
  EventTypeAppInactive = 9,
  EventTypeAppMemoryWarning = 10,
  EventTypeAppDestroyed = 11,
  EventTypeAppOpenedFromUrl = 12,
  EventTypeActionSent = 13,
  EventTypeButtonTapped = 14,
  EventTypePickerSelected = 15,
  EventTypeTextFieldEntered = 16,
  EventTypeGestureLocation = 17,
  EventTypeGestureCaptured = 18,
  EventTypeUrlGenerated = 19,
  EventTypeKeyboardShow = 20,
  EventTypeKeyboardHide = 21,
  EventTypeLabelTextSet = 22,
  EventTypeVendorEvent = 23,
};


SWIFT_CLASS("_TtC13NamogooIBPSDK18EventTypeConverter")
@interface EventTypeConverter : NSObject
+ (NSString * _Nonnull)eventNameFrom:(enum EventType)event SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class SwizzleLogObject;

SWIFT_CLASS("_TtC13NamogooIBPSDK16EventsDispatcher")
@interface EventsDispatcher : NSObject
+ (void)injectEvent:(SwizzleLogObject * _Nonnull)type;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, IBPAutomaticDisplayPermission, open) {
  IBPAutomaticDisplayPermissionBlock = 0,
  IBPAutomaticDisplayPermissionAllow = 1,
  IBPAutomaticDisplayPermissionDefaultSettings = 2,
};

enum IBPCurrency : NSInteger;
@class IBPCartItem;

SWIFT_PROTOCOL("_TtP13NamogooIBPSDK15IBPCartDelegate_")
@protocol IBPCartDelegate
- (double)getCartTotal SWIFT_WARN_UNUSED_RESULT;
- (double)getCartSubtotal SWIFT_WARN_UNUSED_RESULT;
- (enum IBPCurrency)getUserCurrency SWIFT_WARN_UNUSED_RESULT;
- (NSArray<IBPCartItem *> * _Nonnull)getCartItems SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC13NamogooIBPSDK11IBPCartItem")
@interface IBPCartItem : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC13NamogooIBPSDK16IBPConfigManager")
@interface IBPConfigManager : NSObject
+ (NSArray<NSString *> * _Nullable)getRulesForTypeName:(NSString * _Nonnull)type container:(NSString * _Nullable)containingVC class:(NSString * _Nullable)objectClass SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, IBPCurrency, open) {
  IBPCurrencyAED = 0,
  IBPCurrencyAFN = 1,
  IBPCurrencyALL = 2,
  IBPCurrencyAMD = 3,
  IBPCurrencyANG = 4,
  IBPCurrencyAOA = 5,
  IBPCurrencyARS = 6,
  IBPCurrencyAUD = 7,
  IBPCurrencyAWG = 8,
  IBPCurrencyAZN = 9,
  IBPCurrencyBAM = 10,
  IBPCurrencyBBD = 11,
  IBPCurrencyBDT = 12,
  IBPCurrencyBGN = 13,
  IBPCurrencyBHD = 14,
  IBPCurrencyBIF = 15,
  IBPCurrencyBMD = 16,
  IBPCurrencyBND = 17,
  IBPCurrencyBOB = 18,
  IBPCurrencyBRL = 19,
  IBPCurrencyBSD = 20,
  IBPCurrencyBTC = 21,
  IBPCurrencyBTN = 22,
  IBPCurrencyBWP = 23,
  IBPCurrencyBYN = 24,
  IBPCurrencyBZD = 25,
  IBPCurrencyCAD = 26,
  IBPCurrencyCDF = 27,
  IBPCurrencyCHF = 28,
  IBPCurrencyCLF = 29,
  IBPCurrencyCLP = 30,
  IBPCurrencyCNH = 31,
  IBPCurrencyCNY = 32,
  IBPCurrencyCOP = 33,
  IBPCurrencyCRC = 34,
  IBPCurrencyCUC = 35,
  IBPCurrencyCUP = 36,
  IBPCurrencyCVE = 37,
  IBPCurrencyCZK = 38,
  IBPCurrencyDJF = 39,
  IBPCurrencyDKK = 40,
  IBPCurrencyDOP = 41,
  IBPCurrencyDZD = 42,
  IBPCurrencyEGP = 43,
  IBPCurrencyERN = 44,
  IBPCurrencyETB = 45,
  IBPCurrencyEUR = 46,
  IBPCurrencyFJD = 47,
  IBPCurrencyFKP = 48,
  IBPCurrencyGBP = 49,
  IBPCurrencyGEL = 50,
  IBPCurrencyGGP = 51,
  IBPCurrencyGHS = 52,
  IBPCurrencyGIP = 53,
  IBPCurrencyGMD = 54,
  IBPCurrencyGNF = 55,
  IBPCurrencyGTQ = 56,
  IBPCurrencyGYD = 57,
  IBPCurrencyHKD = 58,
  IBPCurrencyHNL = 59,
  IBPCurrencyHRK = 60,
  IBPCurrencyHTG = 61,
  IBPCurrencyHUF = 62,
  IBPCurrencyIDR = 63,
  IBPCurrencyILS = 64,
  IBPCurrencyIMP = 65,
  IBPCurrencyINR = 66,
  IBPCurrencyIQD = 67,
  IBPCurrencyIRR = 68,
  IBPCurrencyISK = 69,
  IBPCurrencyJEP = 70,
  IBPCurrencyJMD = 71,
  IBPCurrencyJOD = 72,
  IBPCurrencyJPY = 73,
  IBPCurrencyKES = 74,
  IBPCurrencyKGS = 75,
  IBPCurrencyKHR = 76,
  IBPCurrencyKMF = 77,
  IBPCurrencyKPW = 78,
  IBPCurrencyKRW = 79,
  IBPCurrencyKWD = 80,
  IBPCurrencyKYD = 81,
  IBPCurrencyKZT = 82,
  IBPCurrencyLAK = 83,
  IBPCurrencyLBP = 84,
  IBPCurrencyLKR = 85,
  IBPCurrencyLRD = 86,
  IBPCurrencyLSL = 87,
  IBPCurrencyLYD = 88,
  IBPCurrencyMAD = 89,
  IBPCurrencyMDL = 90,
  IBPCurrencyMGA = 91,
  IBPCurrencyMKD = 92,
  IBPCurrencyMMK = 93,
  IBPCurrencyMNT = 94,
  IBPCurrencyMOP = 95,
  IBPCurrencyMRO = 96,
  IBPCurrencyMRU = 97,
  IBPCurrencyMUR = 98,
  IBPCurrencyMVR = 99,
  IBPCurrencyMWK = 100,
  IBPCurrencyMXN = 101,
  IBPCurrencyMYR = 102,
  IBPCurrencyMZN = 103,
  IBPCurrencyNAD = 104,
  IBPCurrencyNGN = 105,
  IBPCurrencyNIO = 106,
  IBPCurrencyNOK = 107,
  IBPCurrencyNPR = 108,
  IBPCurrencyNZD = 109,
  IBPCurrencyOMR = 110,
  IBPCurrencyPAB = 111,
  IBPCurrencyPEN = 112,
  IBPCurrencyPGK = 113,
  IBPCurrencyPHP = 114,
  IBPCurrencyPKR = 115,
  IBPCurrencyPLN = 116,
  IBPCurrencyPYG = 117,
  IBPCurrencyQAR = 118,
  IBPCurrencyRON = 119,
  IBPCurrencyRSD = 120,
  IBPCurrencyRUB = 121,
  IBPCurrencyRWF = 122,
  IBPCurrencySAR = 123,
  IBPCurrencySBD = 124,
  IBPCurrencySCR = 125,
  IBPCurrencySDG = 126,
  IBPCurrencySEK = 127,
  IBPCurrencySGD = 128,
  IBPCurrencySHP = 129,
  IBPCurrencySLL = 130,
  IBPCurrencySOS = 131,
  IBPCurrencySRD = 132,
  IBPCurrencySSP = 133,
  IBPCurrencySTD = 134,
  IBPCurrencySTN = 135,
  IBPCurrencySVC = 136,
  IBPCurrencySYP = 137,
  IBPCurrencySZL = 138,
  IBPCurrencyTHB = 139,
  IBPCurrencyTJS = 140,
  IBPCurrencyTMT = 141,
  IBPCurrencyTND = 142,
  IBPCurrencyTOP = 143,
  IBPCurrencyTRY = 144,
  IBPCurrencyTTD = 145,
  IBPCurrencyTWD = 146,
  IBPCurrencyTZS = 147,
  IBPCurrencyUAH = 148,
  IBPCurrencyUGX = 149,
  IBPCurrencyUSD = 150,
  IBPCurrencyUYU = 151,
  IBPCurrencyUZS = 152,
  IBPCurrencyVES = 153,
  IBPCurrencyVND = 154,
  IBPCurrencyVUV = 155,
  IBPCurrencyWST = 156,
  IBPCurrencyXAF = 157,
  IBPCurrencyXAG = 158,
  IBPCurrencyXAU = 159,
  IBPCurrencyXCD = 160,
  IBPCurrencyXDR = 161,
  IBPCurrencyXOF = 162,
  IBPCurrencyXPD = 163,
  IBPCurrencyXPF = 164,
  IBPCurrencyXPT = 165,
  IBPCurrencyYER = 166,
  IBPCurrencyZAR = 167,
  IBPCurrencyZMW = 168,
  IBPCurrencyZWL = 169,
};

typedef SWIFT_ENUM(NSInteger, IBPErrorType, open) {
  IBPErrorTypeNotEligable = 0,
  IBPErrorTypeServerError = 1,
  IBPErrorTypeUndecided = 2,
};

typedef SWIFT_ENUM(NSInteger, IBPEventType, open) {
  IBPEventTypeClickLogIn = 0,
  IBPEventTypeClickLogOut = 1,
  IBPEventTypeClickCreatedAccount = 2,
  IBPEventTypeClickAddToCart = 3,
  IBPEventTypeClickRemovedFromCart = 4,
  IBPEventTypeClickSubscribe = 5,
  IBPEventTypeClickUnsubscribe = 6,
  IBPEventTypeClickStartReview = 7,
  IBPEventTypeClickSubmitReview = 8,
  IBPEventTypeClickCheckOut = 9,
  IBPEventTypeClickContinueAsGuest = 10,
  IBPEventTypePaidWithSpecificPaymentProvider = 11,
  IBPEventTypeUpdatedAccount = 12,
  IBPEventTypeEngagedWithLiveChat = 13,
  IBPEventTypeScreenEntered = 14,
  IBPEventTypeScreenExit = 15,
  IBPEventTypeOpenedFromUrl = 16,
  IBPEventTypeIncentiveReceived = 17,
  IBPEventTypeCouponCopy = 18,
  IBPEventTypeWidgetClick = 19,
  IBPEventTypeWidgetShow = 20,
  IBPEventTypeOrderCompleted = 21,
  IBPEventTypeCouponAdded = 22,
  IBPEventTypePageView = 23,
};


SWIFT_CLASS("_TtC13NamogooIBPSDK18IBPIncentiveStatus")
@interface IBPIncentiveStatus : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC13NamogooIBPSDK14IBPOrderParams")
@interface IBPOrderParams : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class UIImage;

SWIFT_CLASS("_TtC13NamogooIBPSDK11ImageHasher")
@interface ImageHasher : NSObject
+ (NSString * _Nonnull)hashFrom:(UIImage * _Nonnull)image SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS_NAMED("PreviousValidCart")
@interface PreviousValidCart : NSManagedObject
- (nonnull instancetype)initWithEntity:(NSEntityDescription * _Nonnull)entity insertIntoManagedObjectContext:(NSManagedObjectContext * _Nullable)context OBJC_DESIGNATED_INITIALIZER;
@end


@interface PreviousValidCart (SWIFT_EXTENSION(NamogooIBPSDK))
@property (nonatomic) int64_t getAmountInCart;
@property (nonatomic) double getCartSubtotal;
@property (nonatomic) double getCartTotal;
@property (nonatomic, copy) NSString * _Nullable sessionId;
@end


SWIFT_CLASS_NAMED("SessionTime")
@interface SessionTime : NSManagedObject
- (nonnull instancetype)initWithEntity:(NSEntityDescription * _Nonnull)entity insertIntoManagedObjectContext:(NSManagedObjectContext * _Nullable)context OBJC_DESIGNATED_INITIALIZER;
@end


@interface SessionTime (SWIFT_EXTENSION(NamogooIBPSDK))
@property (nonatomic) double sessionEnd;
@property (nonatomic, copy) NSString * _Nullable sessionId;
@property (nonatomic) double sessionStart;
@end






SWIFT_CLASS_NAMED("ViewControllerTime")
@interface ViewControllerTime : NSManagedObject
- (nonnull instancetype)initWithEntity:(NSEntityDescription * _Nonnull)entity insertIntoManagedObjectContext:(NSManagedObjectContext * _Nullable)context OBJC_DESIGNATED_INITIALIZER;
@end


@interface ViewControllerTime (SWIFT_EXTENSION(NamogooIBPSDK))
@property (nonatomic, copy) NSString * _Nullable classIdentifier;
@property (nonatomic, copy) NSDate * _Nullable endTime;
@property (nonatomic, copy) NSString * _Nullable section;
@property (nonatomic, copy) NSString * _Nullable sessionId;
@property (nonatomic, copy) NSDate * _Nullable startTime;
@end


#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif

#elif defined(__x86_64__) && __x86_64__
// Generated by Apple Swift version 5.3.2 (swiftlang-1200.0.45 clang-1200.0.32.28)
#ifndef NAMOGOOIBPSDK_SWIFT_H
#define NAMOGOOIBPSDK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreData;
@import Foundation;
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="NamogooIBPSDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class NSEntityDescription;
@class NSManagedObjectContext;

SWIFT_CLASS_NAMED("Cart")
@interface Cart : NSManagedObject
- (nonnull instancetype)initWithEntity:(NSEntityDescription * _Nonnull)entity insertIntoManagedObjectContext:(NSManagedObjectContext * _Nullable)context OBJC_DESIGNATED_INITIALIZER;
@end


@interface Cart (SWIFT_EXTENSION(NamogooIBPSDK))
@property (nonatomic, copy) NSDate * _Nullable date;
@property (nonatomic, copy) NSString * _Nullable sessionId;
@property (nonatomic) double subtotal;
@property (nonatomic) double subtotalInDefault;
@property (nonatomic) double total;
@property (nonatomic) double totalInDefault;
@end


SWIFT_CLASS_NAMED("Event")
@interface Event : NSManagedObject
- (nonnull instancetype)initWithEntity:(NSEntityDescription * _Nonnull)entity insertIntoManagedObjectContext:(NSManagedObjectContext * _Nullable)context OBJC_DESIGNATED_INITIALIZER;
@end


@interface Event (SWIFT_EXTENSION(NamogooIBPSDK))
@property (nonatomic, copy) NSString * _Nullable id;
@property (nonatomic) BOOL sent;
@property (nonatomic, copy) NSString * _Nullable sessionid;
@property (nonatomic) double time;
@property (nonatomic, copy) NSString * _Nullable type;
@property (nonatomic, copy) NSData * _Nullable value;
@end

typedef SWIFT_ENUM(NSInteger, EventParamConsts, open) {
  EventParamConstsRuleName = 0,
  EventParamConstsViewController = 1,
  EventParamConstsVendorEventType = 2,
};


SWIFT_CLASS("_TtC13NamogooIBPSDK19EventParamConverter")
@interface EventParamConverter : NSObject
+ (NSString * _Nonnull)paramName:(enum EventParamConsts)event SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, EventType, open) {
  EventTypeComponentInit = 0,
  EventTypeComponentForeground = 1,
  EventTypeComponentBackground = 2,
  EventTypeComponentRemovedFromVisualHeirarchy = 3,
  EventTypeComponentAddedToVisualHeirarchy = 4,
  EventTypeAppActive = 5,
  EventTypeAppBackground = 6,
  EventTypeAppForeground = 7,
  EventTypeAppInit = 8,
  EventTypeAppInactive = 9,
  EventTypeAppMemoryWarning = 10,
  EventTypeAppDestroyed = 11,
  EventTypeAppOpenedFromUrl = 12,
  EventTypeActionSent = 13,
  EventTypeButtonTapped = 14,
  EventTypePickerSelected = 15,
  EventTypeTextFieldEntered = 16,
  EventTypeGestureLocation = 17,
  EventTypeGestureCaptured = 18,
  EventTypeUrlGenerated = 19,
  EventTypeKeyboardShow = 20,
  EventTypeKeyboardHide = 21,
  EventTypeLabelTextSet = 22,
  EventTypeVendorEvent = 23,
};


SWIFT_CLASS("_TtC13NamogooIBPSDK18EventTypeConverter")
@interface EventTypeConverter : NSObject
+ (NSString * _Nonnull)eventNameFrom:(enum EventType)event SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class SwizzleLogObject;

SWIFT_CLASS("_TtC13NamogooIBPSDK16EventsDispatcher")
@interface EventsDispatcher : NSObject
+ (void)injectEvent:(SwizzleLogObject * _Nonnull)type;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, IBPAutomaticDisplayPermission, open) {
  IBPAutomaticDisplayPermissionBlock = 0,
  IBPAutomaticDisplayPermissionAllow = 1,
  IBPAutomaticDisplayPermissionDefaultSettings = 2,
};

enum IBPCurrency : NSInteger;
@class IBPCartItem;

SWIFT_PROTOCOL("_TtP13NamogooIBPSDK15IBPCartDelegate_")
@protocol IBPCartDelegate
- (double)getCartTotal SWIFT_WARN_UNUSED_RESULT;
- (double)getCartSubtotal SWIFT_WARN_UNUSED_RESULT;
- (enum IBPCurrency)getUserCurrency SWIFT_WARN_UNUSED_RESULT;
- (NSArray<IBPCartItem *> * _Nonnull)getCartItems SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC13NamogooIBPSDK11IBPCartItem")
@interface IBPCartItem : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC13NamogooIBPSDK16IBPConfigManager")
@interface IBPConfigManager : NSObject
+ (NSArray<NSString *> * _Nullable)getRulesForTypeName:(NSString * _Nonnull)type container:(NSString * _Nullable)containingVC class:(NSString * _Nullable)objectClass SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, IBPCurrency, open) {
  IBPCurrencyAED = 0,
  IBPCurrencyAFN = 1,
  IBPCurrencyALL = 2,
  IBPCurrencyAMD = 3,
  IBPCurrencyANG = 4,
  IBPCurrencyAOA = 5,
  IBPCurrencyARS = 6,
  IBPCurrencyAUD = 7,
  IBPCurrencyAWG = 8,
  IBPCurrencyAZN = 9,
  IBPCurrencyBAM = 10,
  IBPCurrencyBBD = 11,
  IBPCurrencyBDT = 12,
  IBPCurrencyBGN = 13,
  IBPCurrencyBHD = 14,
  IBPCurrencyBIF = 15,
  IBPCurrencyBMD = 16,
  IBPCurrencyBND = 17,
  IBPCurrencyBOB = 18,
  IBPCurrencyBRL = 19,
  IBPCurrencyBSD = 20,
  IBPCurrencyBTC = 21,
  IBPCurrencyBTN = 22,
  IBPCurrencyBWP = 23,
  IBPCurrencyBYN = 24,
  IBPCurrencyBZD = 25,
  IBPCurrencyCAD = 26,
  IBPCurrencyCDF = 27,
  IBPCurrencyCHF = 28,
  IBPCurrencyCLF = 29,
  IBPCurrencyCLP = 30,
  IBPCurrencyCNH = 31,
  IBPCurrencyCNY = 32,
  IBPCurrencyCOP = 33,
  IBPCurrencyCRC = 34,
  IBPCurrencyCUC = 35,
  IBPCurrencyCUP = 36,
  IBPCurrencyCVE = 37,
  IBPCurrencyCZK = 38,
  IBPCurrencyDJF = 39,
  IBPCurrencyDKK = 40,
  IBPCurrencyDOP = 41,
  IBPCurrencyDZD = 42,
  IBPCurrencyEGP = 43,
  IBPCurrencyERN = 44,
  IBPCurrencyETB = 45,
  IBPCurrencyEUR = 46,
  IBPCurrencyFJD = 47,
  IBPCurrencyFKP = 48,
  IBPCurrencyGBP = 49,
  IBPCurrencyGEL = 50,
  IBPCurrencyGGP = 51,
  IBPCurrencyGHS = 52,
  IBPCurrencyGIP = 53,
  IBPCurrencyGMD = 54,
  IBPCurrencyGNF = 55,
  IBPCurrencyGTQ = 56,
  IBPCurrencyGYD = 57,
  IBPCurrencyHKD = 58,
  IBPCurrencyHNL = 59,
  IBPCurrencyHRK = 60,
  IBPCurrencyHTG = 61,
  IBPCurrencyHUF = 62,
  IBPCurrencyIDR = 63,
  IBPCurrencyILS = 64,
  IBPCurrencyIMP = 65,
  IBPCurrencyINR = 66,
  IBPCurrencyIQD = 67,
  IBPCurrencyIRR = 68,
  IBPCurrencyISK = 69,
  IBPCurrencyJEP = 70,
  IBPCurrencyJMD = 71,
  IBPCurrencyJOD = 72,
  IBPCurrencyJPY = 73,
  IBPCurrencyKES = 74,
  IBPCurrencyKGS = 75,
  IBPCurrencyKHR = 76,
  IBPCurrencyKMF = 77,
  IBPCurrencyKPW = 78,
  IBPCurrencyKRW = 79,
  IBPCurrencyKWD = 80,
  IBPCurrencyKYD = 81,
  IBPCurrencyKZT = 82,
  IBPCurrencyLAK = 83,
  IBPCurrencyLBP = 84,
  IBPCurrencyLKR = 85,
  IBPCurrencyLRD = 86,
  IBPCurrencyLSL = 87,
  IBPCurrencyLYD = 88,
  IBPCurrencyMAD = 89,
  IBPCurrencyMDL = 90,
  IBPCurrencyMGA = 91,
  IBPCurrencyMKD = 92,
  IBPCurrencyMMK = 93,
  IBPCurrencyMNT = 94,
  IBPCurrencyMOP = 95,
  IBPCurrencyMRO = 96,
  IBPCurrencyMRU = 97,
  IBPCurrencyMUR = 98,
  IBPCurrencyMVR = 99,
  IBPCurrencyMWK = 100,
  IBPCurrencyMXN = 101,
  IBPCurrencyMYR = 102,
  IBPCurrencyMZN = 103,
  IBPCurrencyNAD = 104,
  IBPCurrencyNGN = 105,
  IBPCurrencyNIO = 106,
  IBPCurrencyNOK = 107,
  IBPCurrencyNPR = 108,
  IBPCurrencyNZD = 109,
  IBPCurrencyOMR = 110,
  IBPCurrencyPAB = 111,
  IBPCurrencyPEN = 112,
  IBPCurrencyPGK = 113,
  IBPCurrencyPHP = 114,
  IBPCurrencyPKR = 115,
  IBPCurrencyPLN = 116,
  IBPCurrencyPYG = 117,
  IBPCurrencyQAR = 118,
  IBPCurrencyRON = 119,
  IBPCurrencyRSD = 120,
  IBPCurrencyRUB = 121,
  IBPCurrencyRWF = 122,
  IBPCurrencySAR = 123,
  IBPCurrencySBD = 124,
  IBPCurrencySCR = 125,
  IBPCurrencySDG = 126,
  IBPCurrencySEK = 127,
  IBPCurrencySGD = 128,
  IBPCurrencySHP = 129,
  IBPCurrencySLL = 130,
  IBPCurrencySOS = 131,
  IBPCurrencySRD = 132,
  IBPCurrencySSP = 133,
  IBPCurrencySTD = 134,
  IBPCurrencySTN = 135,
  IBPCurrencySVC = 136,
  IBPCurrencySYP = 137,
  IBPCurrencySZL = 138,
  IBPCurrencyTHB = 139,
  IBPCurrencyTJS = 140,
  IBPCurrencyTMT = 141,
  IBPCurrencyTND = 142,
  IBPCurrencyTOP = 143,
  IBPCurrencyTRY = 144,
  IBPCurrencyTTD = 145,
  IBPCurrencyTWD = 146,
  IBPCurrencyTZS = 147,
  IBPCurrencyUAH = 148,
  IBPCurrencyUGX = 149,
  IBPCurrencyUSD = 150,
  IBPCurrencyUYU = 151,
  IBPCurrencyUZS = 152,
  IBPCurrencyVES = 153,
  IBPCurrencyVND = 154,
  IBPCurrencyVUV = 155,
  IBPCurrencyWST = 156,
  IBPCurrencyXAF = 157,
  IBPCurrencyXAG = 158,
  IBPCurrencyXAU = 159,
  IBPCurrencyXCD = 160,
  IBPCurrencyXDR = 161,
  IBPCurrencyXOF = 162,
  IBPCurrencyXPD = 163,
  IBPCurrencyXPF = 164,
  IBPCurrencyXPT = 165,
  IBPCurrencyYER = 166,
  IBPCurrencyZAR = 167,
  IBPCurrencyZMW = 168,
  IBPCurrencyZWL = 169,
};

typedef SWIFT_ENUM(NSInteger, IBPErrorType, open) {
  IBPErrorTypeNotEligable = 0,
  IBPErrorTypeServerError = 1,
  IBPErrorTypeUndecided = 2,
};

typedef SWIFT_ENUM(NSInteger, IBPEventType, open) {
  IBPEventTypeClickLogIn = 0,
  IBPEventTypeClickLogOut = 1,
  IBPEventTypeClickCreatedAccount = 2,
  IBPEventTypeClickAddToCart = 3,
  IBPEventTypeClickRemovedFromCart = 4,
  IBPEventTypeClickSubscribe = 5,
  IBPEventTypeClickUnsubscribe = 6,
  IBPEventTypeClickStartReview = 7,
  IBPEventTypeClickSubmitReview = 8,
  IBPEventTypeClickCheckOut = 9,
  IBPEventTypeClickContinueAsGuest = 10,
  IBPEventTypePaidWithSpecificPaymentProvider = 11,
  IBPEventTypeUpdatedAccount = 12,
  IBPEventTypeEngagedWithLiveChat = 13,
  IBPEventTypeScreenEntered = 14,
  IBPEventTypeScreenExit = 15,
  IBPEventTypeOpenedFromUrl = 16,
  IBPEventTypeIncentiveReceived = 17,
  IBPEventTypeCouponCopy = 18,
  IBPEventTypeWidgetClick = 19,
  IBPEventTypeWidgetShow = 20,
  IBPEventTypeOrderCompleted = 21,
  IBPEventTypeCouponAdded = 22,
  IBPEventTypePageView = 23,
};


SWIFT_CLASS("_TtC13NamogooIBPSDK18IBPIncentiveStatus")
@interface IBPIncentiveStatus : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC13NamogooIBPSDK14IBPOrderParams")
@interface IBPOrderParams : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class UIImage;

SWIFT_CLASS("_TtC13NamogooIBPSDK11ImageHasher")
@interface ImageHasher : NSObject
+ (NSString * _Nonnull)hashFrom:(UIImage * _Nonnull)image SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS_NAMED("PreviousValidCart")
@interface PreviousValidCart : NSManagedObject
- (nonnull instancetype)initWithEntity:(NSEntityDescription * _Nonnull)entity insertIntoManagedObjectContext:(NSManagedObjectContext * _Nullable)context OBJC_DESIGNATED_INITIALIZER;
@end


@interface PreviousValidCart (SWIFT_EXTENSION(NamogooIBPSDK))
@property (nonatomic) int64_t getAmountInCart;
@property (nonatomic) double getCartSubtotal;
@property (nonatomic) double getCartTotal;
@property (nonatomic, copy) NSString * _Nullable sessionId;
@end


SWIFT_CLASS_NAMED("SessionTime")
@interface SessionTime : NSManagedObject
- (nonnull instancetype)initWithEntity:(NSEntityDescription * _Nonnull)entity insertIntoManagedObjectContext:(NSManagedObjectContext * _Nullable)context OBJC_DESIGNATED_INITIALIZER;
@end


@interface SessionTime (SWIFT_EXTENSION(NamogooIBPSDK))
@property (nonatomic) double sessionEnd;
@property (nonatomic, copy) NSString * _Nullable sessionId;
@property (nonatomic) double sessionStart;
@end






SWIFT_CLASS_NAMED("ViewControllerTime")
@interface ViewControllerTime : NSManagedObject
- (nonnull instancetype)initWithEntity:(NSEntityDescription * _Nonnull)entity insertIntoManagedObjectContext:(NSManagedObjectContext * _Nullable)context OBJC_DESIGNATED_INITIALIZER;
@end


@interface ViewControllerTime (SWIFT_EXTENSION(NamogooIBPSDK))
@property (nonatomic, copy) NSString * _Nullable classIdentifier;
@property (nonatomic, copy) NSDate * _Nullable endTime;
@property (nonatomic, copy) NSString * _Nullable section;
@property (nonatomic, copy) NSString * _Nullable sessionId;
@property (nonatomic, copy) NSDate * _Nullable startTime;
@end


#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif

#endif
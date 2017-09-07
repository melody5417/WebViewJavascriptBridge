//
//  WKWebViewJavascriptBridge.h
//
//  Created by @LokiMeyburg on 10/15/14.
//  Copyright (c) 2014 @LokiMeyburg. All rights reserved.
//

#if (__MAC_OS_X_VERSION_MAX_ALLOWED > __MAC_10_9 || __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_7_1)
#define supportsWKWebView
#endif

#if defined supportsWKWebView

#import <Foundation/Foundation.h>
#import "WebViewJavascriptBridgeBase.h"
#import <WebKit/WebKit.h>


/**
 * ojbC API
 */
@interface WKWebViewJavascriptBridge : NSObject<WKNavigationDelegate, WebViewJavascriptBridgeBaseDelegate>

/**
 * create a javascript bridge for the given web view.
 */
+ (instancetype)bridgeForWebView:(WKWebView*)webView;
+ (void)enableLogging;

/**
 * register a handler called "handlerName". The javascript can then call this handler with WebViewJavascriptBridge.callHandler("handlerName")
 */
- (void)registerHandler:(NSString*)handlerName handler:(WVJBHandler)handler;
- (void)removeHandler:(NSString*)handlerName;

/**
 * Call the javascript handler called handlerName. If a responseCallback block is given the javascript handler can respond.
 */
- (void)callHandler:(NSString*)handlerName;
- (void)callHandler:(NSString*)handlerName data:(id)data;
- (void)callHandler:(NSString*)handlerName data:(id)data responseCallback:(WVJBResponseCallback)responseCallback;

- (void)reset;

/**
 * Optionally, set a WKNavigationDelegate/UIWebViewDelegate if you need to respond to the web view's lifecycle events.
 */
- (void)setWebViewDelegate:(id)webViewDelegate;

/**
 * UNSAFE. Speed up bridge message passing by disabling the setTimeout safety check. It is only safe to disable this safety check if you do not call any of the javascript popup box functions (alert, confirm, and prompt). If you call any of these functions from the bridged javascript code, the app will hang.
 */
- (void)disableJavscriptAlertBoxSafetyTimeout;

@end

#endif

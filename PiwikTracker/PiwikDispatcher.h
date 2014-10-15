//
//  PiwikDispatcher.h
//  PiwikTracker
//
//  Created by Mattias Levin on 29/08/14.
//  Copyright (c) 2014 Mattias Levin. All rights reserved.
//
@protocol PiwikDispatcher


/**
 Send a single tracking event to the Piwik server.
 
 The dispatcher must send a GET request to the provided path, appending the parameters as a URL encoded query string.

 @param path The path to the Piwik server.
 @param parameters Event parameters. These parameters should be added to the path as a URL encoded query string
 @param successBlock Run the block if the dispatch to the Piwik server is successful.
 @param failure Run this block if the dispatch to the Piwik server fails. Provide a YES to indicate if the SDK should attempt to send any pending event or NO if pending events should be saved until next dispatch. E.g. there is no use trying to send pending events if there is no network connection. */
- (void)sendSingleEventToPath:(NSString*)path
                   parameters:(NSDictionary*)parameters
                      success:(void (^)())successBlock
                      failure:(void (^)(BOOL shouldContinue))failureBlock;

/**
 Send a a batch of tracking event to the Piwik server.
 
 The dispatcher must send a POST request to the provided path, adding the parameters as a JSON encoded body to the request.
 
 @param path The path to the Piwik server.
 @param parameters Event parameters. These parameters should be JSON encoded and added to the request body.
 @param successBlock Run the block if the dispatch to the Piwik server is successful.
 @param failure Run this block if the dispatch to the Piwik server fails. Provide a YES to indicate if the SDK should attempt to send any pending event or NO if pending events should be saved until next dispatch. E.g. there is no use trying to send pending events if there is no network connection.
 */
- (void)sendBatchEventsToPath:(NSString*)path
                   parameters:(NSDictionary*)parameters
                      success:(void (^)())successBlock
                      failure:(void (^)(BOOL shouldContinue))failureBlock;


@end
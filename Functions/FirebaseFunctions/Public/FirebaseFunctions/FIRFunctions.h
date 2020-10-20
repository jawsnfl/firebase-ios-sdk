// Copyright 2017 Google
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class FIRApp;
@class FIRHTTPSCallable;

/**
 * `FIRFunctions` is the client for Cloud Functions for a Firebase project.
 */
NS_SWIFT_NAME(Functions)
@interface FIRFunctions : NSObject

- (id)init NS_UNAVAILABLE;

/**
 * Creates a Cloud Functions client with the default app.
 */
+ (instancetype)functions NS_SWIFT_NAME(functions());

/**
 * Creates a Cloud Functions client with the given app.
 * @param app The app for the Firebase project.
 */
+ (instancetype)functionsForApp:(FIRApp *)app NS_SWIFT_NAME(functions(app:));

/**
 * Creates a Cloud Functions client with the default app and given region.
 * @param region the region for the http trigger, such as "us-central1"
 */
+ (instancetype)functionsForRegion:(NSString *)region;

/**
 * Creates a Cloud Functions client with the default app and given region.
 * @param regionOrCustomDomain One of
 *   a) The region for the http trigger, such as "us-central1"
 *   b) A custom domain for the http trigger, such as "https://mydomain.com"
 */
+ (instancetype)functionsForRegionOrCustomDomain:(NSString *)regionOrCustomDomain NS_SWIFT_NAME(functions(regionOrCustomDomain:));

/**
 * Creates a Cloud Functions client with the given app and region.
 * @param app The app for the Firebase project.
 * @param region The region for the http trigger, such as "us-central1"
 */
// clang-format off
// because it incorrectly breaks this NS_SWIFT_NAME.
+ (instancetype)functionsForApp:(FIRApp *)app
                         region:(NSString *)region;

/**
 * Creates a Cloud Functions client with the given app and region.
 * @param app The app for the Firebase project.
 * @param regionOrCustomDomain One of
 *   a) The region for the http trigger, such as "us-central1"
 *   b) A custom domain for the http trigger, such as "https://mydomain.com" 
 */
// clang-format off
// because it incorrectly breaks this NS_SWIFT_NAME.
+ (instancetype)functionsForApp:(FIRApp *)app
                         regionOrCustomDomain:(NSString *)regionOrCustomDomain NS_SWIFT_NAME(functions(app:regionOrCustomDomain:));
// clang-format on

/**
 * Creates a reference to the Callable HTTPS trigger with the given name.
 * @param name The name of the Callable HTTPS trigger.
 */
- (FIRHTTPSCallable *)HTTPSCallableWithName:(NSString *)name NS_SWIFT_NAME(httpsCallable(_:));

/**
 * Changes this instance to point to a Cloud Functions emulator running locally.
 * See https://firebase.google.com/docs/functions/local-emulator
 * @param origin The origin of the local emulator, such as "http://localhost:5005".
 */
- (void)useFunctionsEmulatorOrigin:(NSString *)origin NS_SWIFT_NAME(useFunctionsEmulator(origin:));

@end

NS_ASSUME_NONNULL_END

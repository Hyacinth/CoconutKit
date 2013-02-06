//
//  CoconutKit_demoAppDelegate.m
//  CoconutKit-demo
//
//  Created by Samuel Défago on 2/10/11.
//  Copyright 2011 Hortis. All rights reserved.
//

#import "CoconutKit_demoAppDelegate.h"

#import "CoconutKit_demoApplication.h"
#import "FolderStorageFileManager.h"

// Disable quasi-simultaneous taps
HLSEnableUIControlExclusiveTouch();

// Enable Core Data easy validation
HLSEnableNSManagedObjectValidation();

// Enable preloading
HLSEnableApplicationPreloading();

@interface CoconutKit_demoAppDelegate ()

@property (nonatomic, retain) CoconutKit_demoApplication *application;

@end

@implementation CoconutKit_demoAppDelegate

#pragma mark Object construction and destruction

- (void)dealloc
{
    self.application = nil;
    self.window = nil;
    [super dealloc];
}

#pragma mark Accessors and mutators

@synthesize application = m_application;

@synthesize window = m_window;

#pragma mark Application lifecycle

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{    
    [self.window makeKeyAndVisible];
    
    // Instead of using the UIAppFonts key in the plist to load the Beon font, do it in code
    [UIFont loadFontWithFileName:@"Beon-Regular.otf" inBundle:nil];
    
    // Test file manager
    FolderStorageFileManager *fileManager = [[[FolderStorageFileManager alloc] init] autorelease];
    [HLSFileManager registerRootDirectory:@"FS" forFileManager:fileManager];
    
    self.application = [[[CoconutKit_demoApplication alloc] init] autorelease];
    self.window.rootViewController = [self.application rootViewController];
    
    return YES;
}

@end

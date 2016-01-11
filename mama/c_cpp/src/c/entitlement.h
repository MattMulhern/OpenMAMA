/* $Id$
 *
 * OpenMAMA: The open middleware agnostic messaging API
 * Copyright (C) 2011 NYSE Technologies, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef EntitlementH__
#define EntitlementH__

//typedef struct entitlementSubscription; //sub level used on a per-supsription basis
typedef void* mamaEntitlementBridge;
typedef void* mamaEntitlementSubscriptionHandle;

typedef struct mamaEntitlementBridge_
{ 
    entitlementBridge   mImpl; /* pointer to implementation bridge struct */

    /* pure functions, defined in entitlement.c */  //TODO: should these even be here??
    entitlementBridge_create                    entitlementCreate;
    entitlementBridge_destroy                   entitlmentDestroy;

    /* implementation functions*/
    entitlementBridge_registerSubjectContext    entitlmentRegisterSubjectContext;
    entitlementBridge_handleNewSubscription     entitlmentHandleNewSubscription;

    void*   mClosure;
} mamaEntitlementBridge;


typedef struct mamaEntitlementSubscription_
{
    mamaEntitlementBridge*    mEntitlementBridge;
} mamaEntitlementSubscription;

//typedef mama_status
//(*entitlementBridge_create) (entitlementBridge**    bridge);

// typedef mama_status
// (*entitlementBridge_destroy) (entitlementBridge**   bridge);

typedef mama_status
(*entitlementBridge_registerSubjectContext) (SubjectContext* ctx);

#endif /* EntitlementH__ */

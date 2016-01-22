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

#include <string.h>
#include <stdio.h>
/* mama */
#include "mama/mama.h"
#include "subscriptionimpl.h"
#include "noent.h"
#include "subscriptionimpl.h"
#include "mamainternal.h"



/*
void entitlementDisconnectCallback (noentClient* client,
                                    const noent_DISCONNECT_REASON reason,
                                    const char * const          userId,
                                    const char * const          host,
                                    const char * const          appName);
void entitlementUpdatedCallback (noentClient*,
                                 int openSubscriptionForbidden);
void entitlementCheckingSwitchCallback (noentClient*,
                                        int isEntitlementsCheckingDisabled);
*/


mama_status
noentEntitlementBridge_registerSubjectContext(SubjectContext* ctx)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "noentEntitlementBridge_registerSubjectContext():");
    /*
    noentSubscription*    noentSub = (noentSubscription*) ctx->mEntitlementBridge->mImpl;

    noentSubscription_addEntitlementCode (noentSub, ctx->mEntitleCode);
    noentSubscription_open (noentSub);
    int result = noentSubscription_isOpen (noentSub);

    if (0 == result)
    {
        mama_log(MAMA_LOG_LEVEL_ERROR,
                 "Could not handle entitlements for new subscription [%s].",
                 ctx->mSymbol);
        return MAMA_STATUS_NOT_ENTITLED;
    }

    */
    return MAMA_STATUS_OK;
}


mama_status
noentEntitlementBridge_destroy(mamaEntitlementBridge bridge)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "noentEntitlementBridge_destroy():");
    return MAMA_STATUS_OK;
}


mama_status
noentEntitlementBridge_init(entitlementBridge* bridge)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "noentEntitlementBridge_init():");

    // Should be an reimplementation of enableEntitlements() previously in mama.c
    noentEntitlementBridge* noentBridge = calloc(1, sizeof(noentEntitlementBridge));

    /* set mamaEntitlemententitlement bridge pointer to bridge implementation struct */
    *bridge = noentEntitlementBridge;

    return MAMA_STATUS_OK;
}


mama_status
noentEntitlementBridge_handleNewSubscription(mamaEntitlementBridge mamaEntBridge, SubjectContext* ctx)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "noentEntitlementBridge_handleNewSubscription():");
    noentEntitlementBridge* noentBridge = (noentEntitlementBridge*) 

    noentEntitlementSubscriptionHandle* noentSubHandle = calloc(1,sizeof(noentEntitlementSubscriptionHandle));

    ctx->mEntitlementBridge = mamaEntBridge;
    ctx->mEntitlementSubscription->mImpl = noentSubHandle;

    return MAMA_STATUS_OK;
}

mama_status
noentEntitlementBridge_setIsSnapshot(entitlementSubscriptionHandle* handle, int isSnapshot)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "noentEntitlementBridge_setIsSnapShot():");
    noentEntitlementSubscriptionHandle* noentSubHandle = (noentEntitlementSubscriptionHandle*) handle;
    handle->mIsSnapshot = isSnapshot;
}

int
noentEntitlementBridge_isAllowed(entitlementSubscriptionHandle* handle, char* subject)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "noentEntitlementBridge_isAllowed():");
    return 1;
}


/*
void
entitlementDisconnectCallback (noentClient*                   client,
                               const noent_DISCONNECT_REASON  reason,
                               const char * const           userId,
                               const char * const           host,
                               const char * const           appName)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "entitlementDisconnectCallback():");

    mamaImpl_entitlementDisconnectCallback(reason, userId, host, appName);
}

void
entitlementUpdatedCallback (noentClient* client,
                            int openSubscriptionForbidden)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "entitlementUpdatedCallback():");

    mamaImpl_entitlementUpdatedCallback();
}

void
entitlementCheckingSwitchCallback (noentClient*   client,
                                   int isEntitlementsCheckingDisabled)
{
    mama_log(MAMA_LOG_LEVEL_FINEST, "entitlementCheckingSwitchCallback():");

    mamaImpl_entitlementCheckingSwitchCallback(isEntitlementsCheckingDisabled);
}
*/




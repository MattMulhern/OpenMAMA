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

#ifndef OeaH__
#define OeaH__


#define OEA_SERVER_PROPERTY     "entitlement.servers"
#define OEA_PORTLOW_PROPERTY    "mama.entitlement.portlow"
#define OEA_PORTHIGH_PROPERTY   "mama.entitlement.porthigh"
#define OEA_ALTUSERID_PROPERTY  "mama.entitlement.altuserid"
#define OEA_SITE_PROPERTY       "mama.entitlement.site"
#define OEA_IP_ADDR_PROPERTY    "mama.entitlement.effective_ip_address"

#define OEA_MAX_ENTITLEMENT_SERVERS 32


typedef struct oeaEntitlementBridge_
{
    // OEA MEMBERS
    oeaClient*  mOeaClient;
} oeaEntitlementBridge;


typedef struct oeaEntitlementSubscriptionHandle_
{
    // OEA MEMBERS
    oeaSubscription*    mOeaSubscription;
} oeaEntitlementSubscriptionHandle;


#endif /* OeaH__ */
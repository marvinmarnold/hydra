/*  =========================================================================
    hydra_msg - The Hydra Protocol
    
    Codec header for hydra_msg.

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

     * The XML model used for this code generation: hydra_msg.xml, or
     * The code generation script that built this file: zproto_codec_c
    ************************************************************************
    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of zbroker, the ZeroMQ broker project.           
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

#ifndef __HYDRA_MSG_H_INCLUDED__
#define __HYDRA_MSG_H_INCLUDED__

/*  These are the hydra_msg messages:

    HELLO - Open new connection and ask for most recent post

    HELLO_OK - Return last post known for peer
        post_id             string      Post identifier

    QUERY - Request list of tags known by peer

    QUERY_OK - Return list of known tags
        tags                strings     List of known tags

    STATUS - Request last post for a given tag

    STATUS_OK - Return last post for given tag
        post_id             string      Post identifier

    FETCH - Fetch a given post
        post_id             string      Post identifier

    FETCH_OK - Return a post details
        post_id             string      Post identifier
        reply_to            string      Parent post, if any
        previous            string      Previous post, if any
        tags                strings     Post tags
        timestamp           number 8    Post creation timestamp
        type                string      Content type
        content             msg         Content body

    INVALID - Command was invalid at this time

    FAILED - Command failed for some specific reason
        reason              string      Reason for failure
*/


#define HYDRA_MSG_HELLO                     1
#define HYDRA_MSG_HELLO_OK                  2
#define HYDRA_MSG_QUERY                     3
#define HYDRA_MSG_QUERY_OK                  4
#define HYDRA_MSG_STATUS                    5
#define HYDRA_MSG_STATUS_OK                 6
#define HYDRA_MSG_FETCH                     7
#define HYDRA_MSG_FETCH_OK                  8
#define HYDRA_MSG_INVALID                   9
#define HYDRA_MSG_FAILED                    10

#include <czmq.h>

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
typedef struct _hydra_msg_t hydra_msg_t;

//  @interface
//  Create a new hydra_msg
hydra_msg_t *
    hydra_msg_new (int id);

//  Destroy the hydra_msg
void
    hydra_msg_destroy (hydra_msg_t **self_p);

//  Parse a hydra_msg from zmsg_t. Returns a new object, or NULL if
//  the message could not be parsed, or was NULL. Destroys msg and 
//  nullifies the msg reference.
hydra_msg_t *
    hydra_msg_decode (zmsg_t **msg_p);

//  Encode hydra_msg into zmsg and destroy it. Returns a newly created
//  object or NULL if error. Use when not in control of sending the message.
zmsg_t *
    hydra_msg_encode (hydra_msg_t **self_p);

//  Receive and parse a hydra_msg from the socket. Returns new object, 
//  or NULL if error. Will block if there's no message waiting.
hydra_msg_t *
    hydra_msg_recv (void *input);

//  Receive and parse a hydra_msg from the socket. Returns new object, 
//  or NULL either if there was no input waiting, or the recv was interrupted.
hydra_msg_t *
    hydra_msg_recv_nowait (void *input);

//  Send the hydra_msg to the output, and destroy it
int
    hydra_msg_send (hydra_msg_t **self_p, void *output);

//  Send the hydra_msg to the output, and do not destroy it
int
    hydra_msg_send_again (hydra_msg_t *self, void *output);

//  Encode the HELLO 
zmsg_t *
    hydra_msg_encode_hello (
);

//  Encode the HELLO_OK 
zmsg_t *
    hydra_msg_encode_hello_ok (
        const char *post_id);

//  Encode the QUERY 
zmsg_t *
    hydra_msg_encode_query (
);

//  Encode the QUERY_OK 
zmsg_t *
    hydra_msg_encode_query_ok (
        zlist_t *tags);

//  Encode the STATUS 
zmsg_t *
    hydra_msg_encode_status (
);

//  Encode the STATUS_OK 
zmsg_t *
    hydra_msg_encode_status_ok (
        const char *post_id);

//  Encode the FETCH 
zmsg_t *
    hydra_msg_encode_fetch (
        const char *post_id);

//  Encode the FETCH_OK 
zmsg_t *
    hydra_msg_encode_fetch_ok (
        const char *post_id,
        const char *reply_to,
        const char *previous,
        zlist_t *tags,
        uint64_t timestamp,
        const char *type,
        zmsg_t *content);

//  Encode the INVALID 
zmsg_t *
    hydra_msg_encode_invalid (
);

//  Encode the FAILED 
zmsg_t *
    hydra_msg_encode_failed (
        const char *reason);


//  Send the HELLO to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
int
    hydra_msg_send_hello (void *output);
    
//  Send the HELLO_OK to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
int
    hydra_msg_send_hello_ok (void *output,
        const char *post_id);
    
//  Send the QUERY to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
int
    hydra_msg_send_query (void *output);
    
//  Send the QUERY_OK to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
int
    hydra_msg_send_query_ok (void *output,
        zlist_t *tags);
    
//  Send the STATUS to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
int
    hydra_msg_send_status (void *output);
    
//  Send the STATUS_OK to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
int
    hydra_msg_send_status_ok (void *output,
        const char *post_id);
    
//  Send the FETCH to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
int
    hydra_msg_send_fetch (void *output,
        const char *post_id);
    
//  Send the FETCH_OK to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
int
    hydra_msg_send_fetch_ok (void *output,
        const char *post_id,
        const char *reply_to,
        const char *previous,
        zlist_t *tags,
        uint64_t timestamp,
        const char *type,
        zmsg_t *content);
    
//  Send the INVALID to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
int
    hydra_msg_send_invalid (void *output);
    
//  Send the FAILED to the output in one step
//  WARNING, this call will fail if output is of type ZMQ_ROUTER.
int
    hydra_msg_send_failed (void *output,
        const char *reason);
    
//  Duplicate the hydra_msg message
hydra_msg_t *
    hydra_msg_dup (hydra_msg_t *self);

//  Print contents of message to stdout
void
    hydra_msg_print (hydra_msg_t *self);

//  Get/set the message routing id
zframe_t *
    hydra_msg_routing_id (hydra_msg_t *self);
void
    hydra_msg_set_routing_id (hydra_msg_t *self, zframe_t *routing_id);

//  Get the hydra_msg id and printable command
int
    hydra_msg_id (hydra_msg_t *self);
void
    hydra_msg_set_id (hydra_msg_t *self, int id);
const char *
    hydra_msg_command (hydra_msg_t *self);

//  Get/set the post_id field
const char *
    hydra_msg_post_id (hydra_msg_t *self);
void
    hydra_msg_set_post_id (hydra_msg_t *self, const char *format, ...);

//  Get/set the tags field
zlist_t *
    hydra_msg_tags (hydra_msg_t *self);
//  Get the tags field and transfer ownership to caller
zlist_t *
    hydra_msg_get_tags (hydra_msg_t *self);
//  Set the tags field, transferring ownership from caller
void
    hydra_msg_set_tags (hydra_msg_t *self, zlist_t **tags_p);

//  Iterate through the tags field, and append a tags value
const char *
    hydra_msg_tags_first (hydra_msg_t *self);
const char *
    hydra_msg_tags_next (hydra_msg_t *self);
void
    hydra_msg_tags_append (hydra_msg_t *self, const char *format, ...);
size_t
    hydra_msg_tags_size (hydra_msg_t *self);

//  Get/set the reply_to field
const char *
    hydra_msg_reply_to (hydra_msg_t *self);
void
    hydra_msg_set_reply_to (hydra_msg_t *self, const char *format, ...);

//  Get/set the previous field
const char *
    hydra_msg_previous (hydra_msg_t *self);
void
    hydra_msg_set_previous (hydra_msg_t *self, const char *format, ...);

//  Get/set the timestamp field
uint64_t
    hydra_msg_timestamp (hydra_msg_t *self);
void
    hydra_msg_set_timestamp (hydra_msg_t *self, uint64_t timestamp);

//  Get/set the type field
const char *
    hydra_msg_type (hydra_msg_t *self);
void
    hydra_msg_set_type (hydra_msg_t *self, const char *format, ...);

//  Get a copy of the content field
zmsg_t *
    hydra_msg_content (hydra_msg_t *self);
//  Get the content field and transfer ownership to caller
zmsg_t *
    hydra_msg_get_content (hydra_msg_t *self);
//  Set the content field, transferring ownership from caller
void
    hydra_msg_set_content (hydra_msg_t *self, zmsg_t **msg_p);

//  Get/set the reason field
const char *
    hydra_msg_reason (hydra_msg_t *self);
void
    hydra_msg_set_reason (hydra_msg_t *self, const char *format, ...);

//  Self test of this class
int
    hydra_msg_test (bool verbose);
//  @end

//  For backwards compatibility with old codecs
#define hydra_msg_dump      hydra_msg_print

#ifdef __cplusplus
}
#endif

#endif
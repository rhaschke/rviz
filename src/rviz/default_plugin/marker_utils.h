/*
 * Copyright (c) 2009, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef RVIZ_MARKER_UTILS_H
#define RVIZ_MARKER_UTILS_H


#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <QString>

namespace Ogre
{
class SceneNode;
}

namespace rviz
{
class DisplayContext;
class MarkerDisplay;
class MarkerBase;

/** Create a marker of given type as declared in visualization_messages::Marker */
MarkerBase* createMarker(int marker_type,
                         MarkerDisplay* owner,
                         DisplayContext* context,
                         Ogre::SceneNode* parent_node);

/** Map marker type ID onto human-readable name */
QString getMarkerTypeName(unsigned int type);

/** Check for correctness of the marker description, issue a warning/error status in the owner if not
 *  Return false if there is a severe error meaning that this marker should be dropped */
bool checkMarkerMsg(const visualization_msgs::Marker& marker, MarkerDisplay* owner);
bool checkMarkerArrayMsg(const visualization_msgs::MarkerArray& array, MarkerDisplay* owner);

} // namespace rviz

#endif

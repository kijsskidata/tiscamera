
#pragma once

#include <gst/gst.h>
#include <vector>
#include <string>
#include <string_view>

namespace gst_helper
{
    /** Converts the passed in gst_list into a std::vector<std::string>
     * @param gst_list Must be GST_VALUE_HOLDS_LIST( &gst_list ) == TRUE and the list values must contain G_TYPE_STRING GValues
     */
    std::vector<std::string>    gst_string_list_to_vector( const GValue& gst_list );
    /** Fetches all GValue pointers from a GST_TYPE_LIST or GST_TYPE_ARRAY in a GValue.
     * Returns a vector of GValue* pointers.
     * Note: These live as long as the GValue passed in lives
     */
    std::vector<const GValue*>  gst_list_or_array_to_GValue_vector( const GValue& gst_list );

    /** Fetches the g_object_get string named 'property_name' and creates a std::string form it.
     */
    std::string     gobject_get_string( gpointer obj, const char* property_name );

    /**
     * Returns a GSList of 'char*' objects.
     * Note: The returned list must be deleted via g_slist_free or its elements deleted via g_slist_remove
     * Note: The contents is a char* pointer which must be deleted via g_free
     */
    GSList*         gst_string_vector_to_GSList( const std::vector<std::string>& lst );
}


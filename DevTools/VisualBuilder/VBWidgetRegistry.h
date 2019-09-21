#pragma once

#include "VBWidgetType.h"
#include <AK/HashMap.h>
#include <AK/NonnullOwnPtrVector.h>
#include <AK/OwnPtr.h>
#include <AK/String.h>
#include <LibGUI/GWidget.h>

class VBProperty;
class VBWidget;

class VBWidgetRegistry {
public:
    template<typename Callback>
    static void for_each_widget_type(Callback callback)
    {
        for (unsigned i = 1; i < (unsigned)VBWidgetType::__Count; ++i)
            callback((VBWidgetType)i);
    }

    static ObjectPtr<GWidget> build_gwidget(VBWidget&, VBWidgetType, GWidget* parent, NonnullOwnPtrVector<VBProperty>&);
};

String to_class_name(VBWidgetType);
VBWidgetType widget_type_from_class_name(const StringView&);

#pragma once

#include <LibGUI/GWidget.h>

class GStackWidget : public GWidget {
    C_OBJECT(GStackWidget)
public:
    explicit GStackWidget(GWidget* parent);
    virtual ~GStackWidget() override;

    GWidget* active_widget() { return m_active_widget.ptr(); }
    const GWidget* active_widget() const { return m_active_widget.ptr(); }
    void set_active_widget(GWidget*);

    Function<void(GWidget*)> on_active_widget_change;

protected:
    virtual void child_event(CChildEvent&) override;
    virtual void resize_event(GResizeEvent&) override;

private:
    ObjectPtr<GWidget> m_active_widget;
};

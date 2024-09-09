// Copyright (c) 2022, NVIDIA CORPORATION. All rights reserved.
//
// NVIDIA CORPORATION and its licensors retain all intellectual property
// and proprietary rights in and to this software, related documentation
// and any modifications thereto. Any use, reproduction, disclosure or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA CORPORATION is strictly prohibited.
//
#pragma once

#include "Api.h"

#include <string>
#include <omni/ui/Widget.h>

using namespace OMNIUI_NS;

ROBOTO_CEF_NAMESPACE_OPEN_SCOPE

/**
 * @brief A simple C++ omni.ui widget that draws a rectangle.
 */
class ROBOTO_CEF_CLASS_API CppWidget : public Widget
{
    OMNIUI_OBJECT(CppWidget)

public:
    ROBOTO_CEF_API ~CppWidget() override;

    /**
     * @brief This property holds the thickness of the rectangle line.
     */
    /// @private (suppress doc generation error)
    OMNIUI_PROPERTY(float, thickness, DEFAULT, 1.0f, READ, getThickness, WRITE, setThickness);

protected:
    /**
     * Constructor.
     */
    ROBOTO_CEF_API CppWidget();

    /**
     * @brief Reimplemented the rendering code of the widget.
     *
     * @see Widget::_drawContent
     */
    ROBOTO_CEF_API void _drawContent(float elapsedTime) override;

private:
};

ROBOTO_CEF_NAMESPACE_CLOSE_SCOPE

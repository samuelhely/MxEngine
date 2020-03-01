// Copyright(c) 2019 - 2020, #Momo
// All rights reserved.
// 
// Redistributionand use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met :
// 
// 1. Redistributions of source code must retain the above copyright notice, this
// list of conditionsand the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditionsand the following disclaimer in the documentation
// and /or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include "PointLight.h"

namespace MxEngine
{
    PointLight& PointLight::UsePosition(const Vector3& position)
    {
        this->Position = position;
        return *this;
    }

    PointLight& PointLight::UseFactors(const Vector3& factors)
    {
        this->factors[Constant] = Max(factors[Constant ], 1.0f);
        this->factors[Linear]   = Max(factors[Linear   ], 0.0f);
        this->factors[Constant] = Max(factors[Quadratic], 0.0f);
        return *this;
    }

    const Vector3& PointLight::GetFactors() const
    {
        return this->factors;
    }

    PointLight& PointLight::UseAmbientColor(const Vector3& ambient)
    {
        this->ambientColor = Clamp(ambient, MakeVector3(0.0f), MakeVector3(1.0f));
        return *this;
    }

    PointLight& PointLight::UseDiffuseColor(const Vector3& diffuse)
    {
        this->diffuseColor = Clamp(diffuse, MakeVector3(0.0f), MakeVector3(1.0f));
        return *this;
    }

    PointLight& PointLight::UseSpecularColor(const Vector3& specular)
    {
        this->specularColor = Clamp(specular, MakeVector3(0.0f), MakeVector3(1.0f));
        return *this;
    }

    const Vector3& PointLight::GetAmbientColor() const
    {
        return this->ambientColor;
    }

    const Vector3& PointLight::GetDiffuseColor() const
    {
        return this->diffuseColor;
    }

    const Vector3& PointLight::GetSpecularColor() const
    {
        return this->specularColor;
    }
}
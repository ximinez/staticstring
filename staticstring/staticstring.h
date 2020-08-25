#pragma once

namespace Json {

    /** \brief Lightweight wrapper to tag static string.
     *
     * Value constructor and objectValue member assignment takes advantage of the
     * StaticString and avoid the cost of string duplication when storing the
     * string or the member name.
     *
     * Example of usage:
     * \code
     * Json::Value aValue( StaticString("some text") );
     * Json::Value object;
     * static const StaticString code("code");
     * object[code] = 1234;
     * \endcode
     */
    class StaticString
    {
    public:
        constexpr explicit StaticString(const char* czstring) : str_(czstring)
        {
        }

        constexpr operator const char* () const
        {
            return str_;
        }

        constexpr const char*
            c_str() const
        {
            return str_;
        }

    private:
        const char* str_;
    };
}


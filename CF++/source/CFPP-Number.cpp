/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014 Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @file        CFPP-Number.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFNumberRef wrapper
 */

#include <CF++.hpp>

#ifdef __clang__
#pragma clang diagnostic ignored "-Wc++11-long-long" /* Do not warn about long long in C++98 */
#endif

namespace CF
{
    Number::Number(): _cfObject( nullptr )
    {
        this->SetSignedIntValue( 0 );
    }
    
    Number::Number( const AutoPointer & value ): _cfObject( nullptr )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( const_cast< void * >( CFRetain( value ) ) );
        }
    }
    
    Number::Number( CFTypeRef cfObject ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
    }
    
    Number::Number( CFNumberRef cfObject ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
    }
    
    Number::Number( std::nullptr_t ): Number( static_cast< CFTypeRef >( nullptr ) )
    {}
    
    Number::Number( const AutoPointer & value, signed char defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->SetSignedCharValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( const AutoPointer & value, signed short defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->SetSignedShortValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( const AutoPointer & value, signed int defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->SetSignedIntValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( const AutoPointer & value, signed long defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->SetSignedLongValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( const AutoPointer & value, signed long long defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->SetSignedLongLongValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( const AutoPointer & value, unsigned char defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->SetUnsignedCharValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( const AutoPointer & value, unsigned short defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->SetUnsignedShortValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( const AutoPointer & value, unsigned int defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->SetUnsignedIntValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( const AutoPointer & value, unsigned long defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->SetUnsignedLongValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( const AutoPointer & value, unsigned long long defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->SetUnsignedLongLongValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( const AutoPointer & value, double defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->SetDoubleValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( const AutoPointer & value, float defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->SetFloatValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFTypeRef cfObject, signed char defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetSignedCharValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFTypeRef cfObject, signed short defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetSignedShortValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFTypeRef cfObject, signed int defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetSignedIntValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFTypeRef cfObject, signed long defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetSignedLongValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFTypeRef cfObject, signed long long defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetSignedLongLongValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFTypeRef cfObject, unsigned char defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetUnsignedCharValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFTypeRef cfObject, unsigned short defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetUnsignedShortValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFTypeRef cfObject, unsigned int defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetUnsignedIntValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFTypeRef cfObject, unsigned long defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetUnsignedLongValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFTypeRef cfObject, unsigned long long defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetUnsignedLongLongValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFTypeRef cfObject, float defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetFloatValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFTypeRef cfObject, double defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetDoubleValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFNumberRef cfObject, signed char defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetSignedCharValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFNumberRef cfObject, signed short defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetSignedShortValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFNumberRef cfObject, signed int defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetSignedIntValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFNumberRef cfObject, signed long defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetSignedLongValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFNumberRef cfObject, signed long long defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetSignedLongLongValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFNumberRef cfObject, unsigned char defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetUnsignedCharValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFNumberRef cfObject, unsigned short defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetUnsignedShortValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFNumberRef cfObject, unsigned int defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetUnsignedIntValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFNumberRef cfObject, unsigned long defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetUnsignedLongValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFNumberRef cfObject, unsigned long long defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetUnsignedLongLongValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFNumberRef cfObject, float defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetFloatValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( CFNumberRef cfObject, double defaultValueIfNULL ): _cfObject( nullptr )
    {
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetDoubleValue( defaultValueIfNULL );
        }
    }
    
    Number::Number( const Number & value ): _cfObject( nullptr )
    {
        if( value._cfObject != nullptr )
        {
            this->_cfObject = static_cast< CFNumberRef >( CFRetain( value._cfObject ) );
        }
    }
    
    Number::Number( signed char value ): _cfObject( nullptr )
    {
        this->SetSignedCharValue( value );
    }
    
    Number::Number( signed short value ): _cfObject( nullptr )
    {
        this->SetSignedShortValue( value );
    }
    
    Number::Number( signed int value ): _cfObject( nullptr )
    {
        this->SetSignedIntValue( value );
    }
    
    Number::Number( signed long value ): _cfObject( nullptr )
    {
        this->SetSignedLongValue( value );
    }
    
    Number::Number( signed long long value ): _cfObject( nullptr )
    {
        this->SetSignedLongLongValue( value );
    }
    
    Number::Number( unsigned char value ): _cfObject( nullptr )
    {
        this->SetUnsignedCharValue( value );
    }
    
    Number::Number( unsigned short value ): _cfObject( nullptr )
    {
        this->SetUnsignedShortValue( value );
    }
    
    Number::Number( unsigned int value ): _cfObject( nullptr )
    {
        this->SetUnsignedIntValue( value );
    }
    
    Number::Number( unsigned long value ): _cfObject( nullptr )
    {
        this->SetUnsignedLongValue( value );
    }
    
    Number::Number( unsigned long long value ): _cfObject( nullptr )
    {
        this->SetUnsignedLongLongValue( value );
    }
    
    Number::Number( float value ): _cfObject( nullptr )
    {
        this->SetFloatValue( value );
    }
    
    Number::Number( double value ): _cfObject( nullptr )
    {
        this->SetDoubleValue( value );
    }
    
    Number::Number( Number && value ) noexcept
    {
        this->_cfObject = value._cfObject;
        value._cfObject = nullptr;
    }
    
    Number::~Number()
    {
        if( this->_cfObject != nullptr )
        {
            CFRelease( this->_cfObject );
            
            this->_cfObject = nullptr;
        }
    }
    
    Number & Number::operator =( Number value )
    {
        swap( *( this ), value );
        
        return *( this );
    }
    
    Number & Number::operator =( const AutoPointer & value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( CFTypeRef value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( CFNumberRef value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( std::nullptr_t )
    {
        return operator =( Number( nullptr ) );
    }
    
    Number & Number::operator =( signed char value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( signed short value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( signed int value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( signed long value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( signed long long value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( unsigned char value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( unsigned short value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( unsigned int value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( unsigned long value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( unsigned long long value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( float value )
    {
        return operator =( Number( value ) );
    }
    
    Number & Number::operator =( double value )
    {
        return operator =( Number( value ) );
    }
    
    bool Number::operator == ( const Number & value ) const
    {
        if( this->IsFloatType() || value.IsFloatType() )
        {
            return fabs( this->GetDoubleValue() - value.GetDoubleValue() ) < DBL_EPSILON;
        }
        
        return this->GetSignedLongValue() == value.GetSignedLongValue();
    }
    
    bool Number::operator == ( CFTypeRef value ) const
    {
        return operator ==( Number( value ) );
    }
    
    bool Number::operator == ( CFNumberRef value ) const
    {
        return operator ==( Number( value ) );
    }
    
    bool Number::operator == ( signed char value ) const
    {
        return operator ==( Number( value ) );
    }
    
    bool Number::operator == ( signed short value ) const
    {
        return operator ==( Number( value ) );
    }
    
    bool Number::operator == ( signed int value ) const
    {
        return operator ==( Number( value ) );
    }
    
    bool Number::operator == ( signed long value ) const
    {
        return operator ==( Number( value ) );
    }
    
    bool Number::operator == ( signed long long value ) const
    {
        return operator ==( Number( value ) );
    }
    
    bool Number::operator == ( unsigned char value ) const
    {
        return operator ==( Number( value ) );
    }
    
    bool Number::operator == ( unsigned short value ) const
    {
        return operator ==( Number( value ) );
    }
    
    bool Number::operator == ( unsigned int value ) const
    {
        return operator ==( Number( value ) );
    }
    
    bool Number::operator == ( unsigned long value ) const
    {
        return operator ==( Number( value ) );
    }
    
    bool Number::operator == ( unsigned long long value ) const
    {
        return operator ==( Number( value ) );
    }
    
    bool Number::operator == ( float value ) const
    {
        return operator ==( Number( value ) );
    }
    
    bool Number::operator == ( double value ) const
    {
        return operator ==( Number( value ) );
    }
            
    bool Number::operator != ( const Number & value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( CFTypeRef value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( CFNumberRef value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( signed char value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( signed short value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( signed int value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( signed long value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( signed long long value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( unsigned char value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( unsigned short value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( unsigned int value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( unsigned long value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( unsigned long long value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( float value ) const
    {
        return !operator ==( value );
    }
    
    bool Number::operator != ( double value ) const
    {
        return !operator ==( value );
    }
            
    bool Number::operator >= ( const Number & value ) const
    {
        if( this->IsFloatType() || value.IsFloatType() )
        {
            return this->GetDoubleValue() >= value.GetDoubleValue();
        }
        
        return this->GetSignedLongValue() >= value.GetSignedLongValue();
    }
    
    bool Number::operator >= ( CFTypeRef value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator >= ( CFNumberRef value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator >= ( signed char value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator >= ( signed short value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator >= ( signed int value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator >= ( signed long value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator >= ( signed long long value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator >= ( unsigned char value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator >= ( unsigned short value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator >= ( unsigned int value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator >= ( unsigned long value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator >= ( unsigned long long value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator >= ( float value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator >= ( double value ) const
    {
        return operator >=( Number( value ) );
    }
    
    bool Number::operator <= ( const Number & value ) const
    {
        if( this->IsFloatType() || value.IsFloatType() )
        {
            return this->GetDoubleValue() <= value.GetDoubleValue();
        }
        
        return this->GetSignedLongValue() <= value.GetSignedLongValue();
    }
    
    bool Number::operator <= ( CFTypeRef value ) const
    {
        return operator <=( Number( value ) );
    }
    
    bool Number::operator <= ( CFNumberRef value ) const
    {
        return operator <=( Number( value ) );
    }
    
    bool Number::operator <= ( signed char value ) const
    {
        return operator <=( Number( value ) );
    }
    
    bool Number::operator <= ( signed short value ) const
    {
        return operator <=( Number( value ) );
    }
    
    bool Number::operator <= ( signed int value ) const
    {
        return operator <=( Number( value ) );
    }
    
    bool Number::operator <= ( signed long value ) const
    {
        return operator <=( Number( value ) );
    }
    
    bool Number::operator <= ( signed long long value ) const
    {
        return operator <=( Number( value ) );
    }
    
    bool Number::operator <= ( unsigned char value ) const
    {
        return operator <=( Number( value ) );
    }
    
    bool Number::operator <= ( unsigned short value ) const
    {
        return operator <=( Number( value ) );
    }
    
    bool Number::operator <= ( unsigned int value ) const
    {
        return operator <=( Number( value ) );
    }
    
    bool Number::operator <= ( unsigned long value ) const
    {
        return operator <=( Number( value ) );
    }
    
    bool Number::operator <= ( unsigned long long value ) const
    {
        return operator <=( Number( value ) );
    }
    
    bool Number::operator <= ( float value ) const
    {
        return operator <=( Number( value ) );
    }
    
    bool Number::operator <= ( double value ) const
    {
        return operator <=( Number( value ) );
    }
            
    bool Number::operator >( const Number & value ) const
    {
        if( this->IsFloatType() || value.IsFloatType() )
        {
            return this->GetDoubleValue() > value.GetDoubleValue();
        }
        
        return this->GetSignedLongValue() > value.GetSignedLongValue();
    }
    
    bool Number::operator >( CFTypeRef value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator >( CFNumberRef value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator >( signed char value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator >( signed short value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator >( signed int value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator >( signed long value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator >( signed long long value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator >( unsigned char value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator >( unsigned short value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator >( unsigned int value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator >( unsigned long value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator >( unsigned long long value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator >( float value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator >( double value ) const
    {
        return operator >( Number( value ) );
    }
    
    bool Number::operator <( const Number & value ) const
    {
        if( this->IsFloatType() || value.IsFloatType() )
        {
            return this->GetDoubleValue() < value.GetDoubleValue();
        }
        
        return this->GetSignedLongValue() < value.GetSignedLongValue();
    }
    
    bool Number::operator <( CFTypeRef value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator <( CFNumberRef value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator <( signed char value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator <( signed short value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator <( signed int value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator <( signed long value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator <( signed long long value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator <( unsigned char value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator <( unsigned short value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator <( unsigned int value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator <( unsigned long value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator <( unsigned long long value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator <( float value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator <( double value ) const
    {
        return operator <( Number( value ) );
    }
    
    bool Number::operator && ( const Number & value ) const
    {
        return this->GetSignedLongValue() && value.GetSignedLongValue();
    }
    
    bool Number::operator && ( CFTypeRef value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator && ( CFNumberRef value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator && ( signed char value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator && ( signed short value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator && ( signed int value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator && ( signed long value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator && ( signed long long value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator && ( unsigned char value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator && ( unsigned short value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator && ( unsigned int value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator && ( unsigned long value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator && ( unsigned long long value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator && ( float value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator && ( double value ) const
    {
        return operator &&( Number( value ) );
    }
    
    bool Number::operator || ( const Number & value ) const
    {
        return this->GetSignedLongValue() || value.GetSignedLongValue();
    }
    
    bool Number::operator || ( CFTypeRef value ) const
    {
        return operator ||( Number( value ) );
    }
    
    bool Number::operator || ( CFNumberRef value ) const
    {
        return operator ||( Number( value ) );
    }
    
    bool Number::operator || ( signed char value ) const
    {
        return operator ||( Number( value ) );
    }
    
    bool Number::operator || ( signed short value ) const
    {
        return operator ||( Number( value ) );
    }
    
    bool Number::operator || ( signed int value ) const
    {
        return operator ||( Number( value ) );
    }
    
    bool Number::operator || ( signed long value ) const
    {
        return operator ||( Number( value ) );
    }
    
    bool Number::operator || ( signed long long value ) const
    {
        return operator ||( Number( value ) );
    }
    
    bool Number::operator || ( unsigned char value ) const
    {
        return operator ||( Number( value ) );
    }
    
    bool Number::operator || ( unsigned short value ) const
    {
        return operator ||( Number( value ) );
    }
    
    bool Number::operator || ( unsigned int value ) const
    {
        return operator ||( Number( value ) );
    }
    
    bool Number::operator || ( unsigned long value ) const
    {
        return operator ||( Number( value ) );
    }
    
    bool Number::operator || ( unsigned long long value ) const
    {
        return operator ||( Number( value ) );
    }
    
    bool Number::operator || ( float value ) const
    {
        return operator ||( Number( value ) );
    }
    
    bool Number::operator || ( double value ) const
    {
        return operator ||( Number( value ) );
    }
    
    Number & Number::operator ~()
    {
        this->SetSignedLongValue( ~( this->GetSignedLongValue() ) );
        
        return *( this );
    }
    
    Number & Number::operator !()
    {
        this->SetSignedLongValue( !( this->GetSignedLongValue() ) );
        
        return *( this );
    }
    
    Number & Number::operator ++ ()
    {
        if( this->IsFloatType() )
        {
            this->SetDoubleValue( this->GetDoubleValue() + static_cast< double >( 1 ) );
        }
        else
        {
            this->SetSignedLongLongValue( this->GetSignedLongLongValue() + static_cast< signed long long >( 1 ) );
        }
        
        return *( this );
    }
    
    Number Number::operator ++ ( int )
    {
        Number n( *( this ) );
        
        operator++();
        
        return n;
    }
    
    Number & Number::operator -- ()
    {
        if( this->IsFloatType() )
        {
            this->SetDoubleValue( this->GetDoubleValue() - static_cast< double >( 1 ) );
        }
        else
        {
            this->SetSignedLongLongValue( this->GetSignedLongLongValue() - static_cast< signed long long >( 1 ) );
        }
        
        return *( this );
    }
    
    Number Number::operator -- ( int )
    {
        Number n( *( this ) );
        
        operator--();
        
        return n;
    }
    
    Number & Number::operator += ( const Number & value )
    {
        if( this->IsFloatType() || value.IsFloatType() )
        {
            this->SetDoubleValue( this->GetDoubleValue() + value.GetDoubleValue() );
        }
        else
        {
            this->SetSignedLongLongValue( this->GetSignedLongLongValue() + value.GetSignedLongLongValue() );
        }
        
        return *( this );
    }
    
    Number & Number::operator += ( CFNumberRef value )
    {
        return operator +=( Number( value ) );
    }
    
    Number & Number::operator += ( signed char value )
    {
        return operator +=( Number( value ) );
    }
    
    Number & Number::operator += ( signed short value )
    {
        return operator +=( Number( value ) );
    }
    
    Number & Number::operator += ( signed int value )
    {
        return operator +=( Number( value ) );
    }
    
    Number & Number::operator += ( signed long value )
    {
        return operator +=( Number( value ) );
    }
    
    Number & Number::operator += ( signed long long value )
    {
        return operator +=( Number( value ) );
    }
    
    Number & Number::operator += ( unsigned char value )
    {
        return operator +=( Number( value ) );
    }
    
    Number & Number::operator += ( unsigned short value )
    {
        return operator +=( Number( value ) );
    }
    
    Number & Number::operator += ( unsigned int value )
    {
        return operator +=( Number( value ) );
    }
    
    Number & Number::operator += ( unsigned long value )
    {
        return operator +=( Number( value ) );
    }
    
    Number & Number::operator += ( unsigned long long value )
    {
        return operator +=( Number( value ) );
    }
    
    Number & Number::operator += ( float value )
    {
        return operator +=( Number( value ) );
    }
    
    Number & Number::operator += ( double value )
    {
        return operator +=( Number( value ) );
    }
    
    Number & Number::operator -= ( const Number & value )
    {
        if( this->IsFloatType() || value.IsFloatType() )
        {
            this->SetDoubleValue( this->GetDoubleValue() - value.GetDoubleValue() );
        }
        else
        {
            this->SetSignedLongValue( this->GetSignedLongValue() - value.GetSignedLongValue() );
        }
        
        return *( this );
    }
    
    Number & Number::operator -= ( CFNumberRef value )
    {
        return operator -=( Number( value ) );
    }
    
    Number & Number::operator -= ( signed char value )
    {
        return operator -=( Number( value ) );
    }
    
    Number & Number::operator -= ( signed short value )
    {
        return operator -=( Number( value ) );
    }
    
    Number & Number::operator -= ( signed int value )
    {
        return operator -=( Number( value ) );
    }
    
    Number & Number::operator -= ( signed long value )
    {
        return operator -=( Number( value ) );
    }
    
    Number & Number::operator -= ( signed long long value )
    {
        return operator -=( Number( value ) );
    }
    
    Number & Number::operator -= ( unsigned char value )
    {
        return operator -=( Number( value ) );
    }
    
    Number & Number::operator -= ( unsigned short value )
    {
        return operator -=( Number( value ) );
    }
    
    Number & Number::operator -= ( unsigned int value )
    {
        return operator -=( Number( value ) );
    }
    
    Number & Number::operator -= ( unsigned long value )
    {
        return operator -=( Number( value ) );
    }
    
    Number & Number::operator -= ( unsigned long long value )
    {
        return operator -=( Number( value ) );
    }
    
    Number & Number::operator -= ( float value )
    {
        return operator -=( Number( value ) );
    }
    
    Number & Number::operator -= ( double value )
    {
        return operator -=( Number( value ) );
    }
    
    Number & Number::operator *= ( const Number & value )
    {
        if( this->IsFloatType() || value.IsFloatType() )
        {
            this->SetDoubleValue( this->GetDoubleValue() * value.GetDoubleValue() );
        }
        else
        {
            this->SetSignedLongValue( this->GetSignedLongValue() * value.GetSignedLongValue() );
        }
        
        return *( this );
    }
    
    Number & Number::operator *= ( CFNumberRef value )
    {
        return operator *=( Number( value ) );
    }
    
    Number & Number::operator *= ( signed char value )
    {
        return operator *=( Number( value ) );
    }
    
    Number & Number::operator *= ( signed short value )
    {
        return operator *=( Number( value ) );
    }
    
    Number & Number::operator *= ( signed int value )
    {
        return operator *=( Number( value ) );
    }
    
    Number & Number::operator *= ( signed long value )
    {
        return operator *=( Number( value ) );
    }
    
    Number & Number::operator *= ( signed long long value )
    {
        return operator *=( Number( value ) );
    }
    
    Number & Number::operator *= ( unsigned char value )
    {
        return operator *=( Number( value ) );
    }
    
    Number & Number::operator *= ( unsigned short value )
    {
        return operator *=( Number( value ) );
    }
    
    Number & Number::operator *= ( unsigned int value )
    {
        return operator *=( Number( value ) );
    }
    
    Number & Number::operator *= ( unsigned long value )
    {
        return operator *=( Number( value ) );
    }
    
    Number & Number::operator *= ( unsigned long long value )
    {
        return operator *=( Number( value ) );
    }
    
    Number & Number::operator *= ( float value )
    {
        return operator *=( Number( value ) );
    }
    
    Number & Number::operator *= ( double value )
    {
        return operator *=( Number( value ) );
    }
    
    Number & Number::operator /= ( const Number & value )
    {
        if( fabs( value.GetDoubleValue() ) < DBL_EPSILON )
        {
            throw std::runtime_error( "Division by zero" );
        }
        
        this->SetDoubleValue( this->GetDoubleValue() / value.GetDoubleValue() );
        
        return *( this );
    }
    
    Number & Number::operator /= ( CFNumberRef value )
    {
        return operator /=( Number( value ) );
    }
    
    Number & Number::operator /= ( signed char value )
    {
        return operator /=( Number( value ) );
    }
    
    Number & Number::operator /= ( signed short value )
    {
        return operator /=( Number( value ) );
    }
    
    Number & Number::operator /= ( signed int value )
    {
        return operator /=( Number( value ) );
    }
    
    Number & Number::operator /= ( signed long value )
    {
        return operator /=( Number( value ) );
    }
    
    Number & Number::operator /= ( signed long long value )
    {
        return operator /=( Number( value ) );
    }
    
    Number & Number::operator /= ( unsigned char value )
    {
        return operator /=( Number( value ) );
    }
    
    Number & Number::operator /= ( unsigned short value )
    {
        return operator /=( Number( value ) );
    }
    
    Number & Number::operator /= ( unsigned int value )
    {
        return operator /=( Number( value ) );
    }
    
    Number & Number::operator /= ( unsigned long value )
    {
        return operator /=( Number( value ) );
    }
    
    Number & Number::operator /= ( unsigned long long value )
    {
        return operator /=( Number( value ) );
    }
    
    Number & Number::operator /= ( float value )
    {
        return operator /=( Number( value ) );
    }
    
    Number & Number::operator /= ( double value )
    {
        return operator /=( Number( value ) );
    }
    
    Number & Number::operator |= ( const Number & value )
    {
        this->SetSignedLongValue( this->GetSignedLongValue() | value.GetSignedLongValue() );
        
        return *( this );
    }
    
    Number & Number::operator |= ( CFNumberRef value )
    {
        return operator |=( Number( value ) );
    }
    
    Number & Number::operator |= ( signed char value )
    {
        return operator |=( Number( value ) );
    }
    
    Number & Number::operator |= ( signed short value )
    {
        return operator |=( Number( value ) );
    }
    
    Number & Number::operator |= ( signed int value )
    {
        return operator |=( Number( value ) );
    }
    
    Number & Number::operator |= ( signed long value )
    {
        return operator |=( Number( value ) );
    }
    
    Number & Number::operator |= ( signed long long value )
    {
        return operator |=( Number( value ) );
    }
    
    Number & Number::operator |= ( unsigned char value )
    {
        return operator |=( Number( value ) );
    }
    
    Number & Number::operator |= ( unsigned short value )
    {
        return operator |=( Number( value ) );
    }
    
    Number & Number::operator |= ( unsigned int value )
    {
        return operator |=( Number( value ) );
    }
    
    Number & Number::operator |= ( unsigned long value )
    {
        return operator |=( Number( value ) );
    }
    
    Number & Number::operator |= ( unsigned long long value )
    {
        return operator |=( Number( value ) );
    }
    
    Number & Number::operator &= ( const Number & value )
    {
        this->SetSignedLongValue( this->GetSignedLongValue() & value.GetSignedLongValue() );
        
        return *( this );
    }
    
    Number & Number::operator &= ( CFNumberRef value )
    {
        return operator &=( Number( value ) );
    }
    
    Number & Number::operator &= ( signed char value )
    {
        return operator &=( Number( value ) );
    }
    
    Number & Number::operator &= ( signed short value )
    {
        return operator &=( Number( value ) );
    }
    
    Number & Number::operator &= ( signed int value )
    {
        return operator &=( Number( value ) );
    }
    
    Number & Number::operator &= ( signed long value )
    {
        return operator &=( Number( value ) );
    }
    
    Number & Number::operator &= ( signed long long value )
    {
        return operator &=( Number( value ) );
    }
    
    Number & Number::operator &= ( unsigned char value )
    {
        return operator &=( Number( value ) );
    }
    
    Number & Number::operator &= ( unsigned short value )
    {
        return operator &=( Number( value ) );
    }
    
    Number & Number::operator &= ( unsigned int value )
    {
        return operator &=( Number( value ) );
    }
    
    Number & Number::operator &= ( unsigned long value )
    {
        return operator &=( Number( value ) );
    }
    
    Number & Number::operator &= ( unsigned long long value )
    {
        return operator &=( Number( value ) );
    }
    
    Number & Number::operator %= ( const Number & value )
    {
        if( value.GetSignedLongValue() == 0 )
        {
            throw std::runtime_error( "Division by zero" );
        }
        
        this->SetSignedLongValue( this->GetSignedLongValue() % value.GetSignedLongValue() );
        
        return *( this );
    }
    
    Number & Number::operator %= ( CFNumberRef value )
    {
        return operator %=( Number( value ) );
    }
    
    Number & Number::operator %= ( signed char value )
    {
        return operator %=( Number( value ) );
    }
    
    Number & Number::operator %= ( signed short value )
    {
        return operator %=( Number( value ) );
    }
    
    Number & Number::operator %= ( signed int value )
    {
        return operator %=( Number( value ) );
    }
    
    Number & Number::operator %= ( signed long value )
    {
        return operator %=( Number( value ) );
    }
    
    Number & Number::operator %= ( signed long long value )
    {
        return operator %=( Number( value ) );
    }
    
    Number & Number::operator %= ( unsigned char value )
    {
        return operator %=( Number( value ) );
    }
    
    Number & Number::operator %= ( unsigned short value )
    {
        return operator %=( Number( value ) );
    }
    
    Number & Number::operator %= ( unsigned int value )
    {
        return operator %=( Number( value ) );
    }
    
    Number & Number::operator %= ( unsigned long value )
    {
        return operator %=( Number( value ) );
    }
    
    Number & Number::operator %= ( unsigned long long value )
    {
        return operator %=( Number( value ) );
    }
    
    Number & Number::operator ^= ( const Number & value )
    {
        this->SetSignedLongValue( this->GetSignedLongValue() ^ value.GetSignedLongValue() );
        
        return *( this );
    }
    
    Number & Number::operator ^= ( CFNumberRef value )
    {
        return operator ^=( Number( value ) );
    }
    
    Number & Number::operator ^= ( signed char value )
    {
        return operator ^=( Number( value ) );
    }
    
    Number & Number::operator ^= ( signed short value )
    {
        return operator ^=( Number( value ) );
    }
    
    Number & Number::operator ^= ( signed int value )
    {
        return operator ^=( Number( value ) );
    }
    
    Number & Number::operator ^= ( signed long value )
    {
        return operator ^=( Number( value ) );
    }
    
    Number & Number::operator ^= ( signed long long value )
    {
        return operator ^=( Number( value ) );
    }
    
    Number & Number::operator ^= ( unsigned char value )
    {
        return operator ^=( Number( value ) );
    }
    
    Number & Number::operator ^= ( unsigned short value )
    {
        return operator ^=( Number( value ) );
    }
    
    Number & Number::operator ^= ( unsigned int value )
    {
        return operator ^=( Number( value ) );
    }
    
    Number & Number::operator ^= ( unsigned long value )
    {
        return operator ^=( Number( value ) );
    }
    
    Number & Number::operator ^= ( unsigned long long value )
    {
        return operator ^=( Number( value ) );
    }
    
    Number & Number::operator <<= ( const Number & value )
    {
        this->SetSignedLongValue( this->GetSignedLongValue() << value.GetSignedLongValue() );
        
        return *( this );
    }
    
    Number & Number::operator <<= ( CFNumberRef value )
    {
        return operator <<=( Number( value ) );
    }
    
    Number & Number::operator <<= ( signed char value )
    {
        return operator <<=( Number( value ) );
    }
    
    Number & Number::operator <<= ( signed short value )
    {
        return operator <<=( Number( value ) );
    }
    
    Number & Number::operator <<= ( signed int value )
    {
        return operator <<=( Number( value ) );
    }
    
    Number & Number::operator <<= ( signed long value )
    {
        return operator <<=( Number( value ) );
    }
    
    Number & Number::operator <<= ( signed long long value )
    {
        return operator <<=( Number( value ) );
    }
    
    Number & Number::operator <<= ( unsigned char value )
    {
        return operator <<=( Number( value ) );
    }
    
    Number & Number::operator <<= ( unsigned short value )
    {
        return operator <<=( Number( value ) );
    }
    
    Number & Number::operator <<= ( unsigned int value )
    {
        return operator <<=( Number( value ) );
    }
    
    Number & Number::operator <<= ( unsigned long value )
    {
        return operator <<=( Number( value ) );
    }
    
    Number & Number::operator <<= ( unsigned long long value )
    {
        return operator <<=( Number( value ) );
    }
    
    Number & Number::operator >>= ( const Number & value )
    {
        this->SetSignedLongValue( this->GetSignedLongValue() >> value.GetSignedLongValue() );
        
        return *( this );
    }
    
    Number & Number::operator >>= ( CFNumberRef value )
    {
        return operator >>=( Number( value ) );
    }
    
    Number & Number::operator >>= ( signed char value )
    {
        return operator >>=( Number( value ) );
    }
    
    Number & Number::operator >>= ( signed short value )
    {
        return operator >>=( Number( value ) );
    }
    
    Number & Number::operator >>= ( signed int value )
    {
        return operator >>=( Number( value ) );
    }
    
    Number & Number::operator >>= ( signed long value )
    {
        return operator >>=( Number( value ) );
    }
    
    Number & Number::operator >>= ( signed long long value )
    {
        return operator >>=( Number( value ) );
    }
    
    Number & Number::operator >>= ( unsigned char value )
    {
        return operator >>=( Number( value ) );
    }
    
    Number & Number::operator >>= ( unsigned short value )
    {
        return operator >>=( Number( value ) );
    }
    
    Number & Number::operator >>= ( unsigned int value )
    {
        return operator >>=( Number( value ) );
    }
    
    Number & Number::operator >>= ( unsigned long value )
    {
        return operator >>=( Number( value ) );
    }
    
    Number & Number::operator >>= ( unsigned long long value )
    {
        return operator >>=( Number( value ) );
    }
    
    Number Number::operator +( const Number & value )
    {
        return Number( *( this ) ) += value;
    }
    
    Number Number::operator +( CFNumberRef value )
    {
        return operator +( Number( value ) );
    }
    
    Number Number::operator +( signed char value )
    {
        return operator +( Number( value ) );
    }
    
    Number Number::operator +( signed short value )
    {
        return operator +( Number( value ) );
    }
    
    Number Number::operator +( signed int value )
    {
        return operator +( Number( value ) );
    }
    
    Number Number::operator +( signed long value )
    {
        return operator +( Number( value ) );
    }
    
    Number Number::operator +( signed long long value )
    {
        return operator +( Number( value ) );
    }
    
    Number Number::operator +( unsigned char value )
    {
        return operator +( Number( value ) );
    }
    
    Number Number::operator +( unsigned short value )
    {
        return operator +( Number( value ) );
    }
    
    Number Number::operator +( unsigned int value )
    {
        return operator +( Number( value ) );
    }
    
    Number Number::operator +( unsigned long value )
    {
        return operator +( Number( value ) );
    }
    
    Number Number::operator +( unsigned long long value )
    {
        return operator +( Number( value ) );
    }
    
    Number Number::operator +( float value )
    {
        return operator +( Number( value ) );
    }
    
    Number Number::operator +( double value )
    {
        return operator +( Number( value ) );
    }
    
    Number Number::operator -( const Number & value )
    {
        return Number( *( this ) ) -= value;
    }
    
    Number Number::operator -( CFNumberRef value )
    {
        return operator -( Number( value ) );
    }
    
    Number Number::operator -( signed char value )
    {
        return operator -( Number( value ) );
    }
    
    Number Number::operator -( signed short value )
    {
        return operator -( Number( value ) );
    }
    
    Number Number::operator -( signed int value )
    {
        return operator -( Number( value ) );
    }
    
    Number Number::operator -( signed long value )
    {
        return operator -( Number( value ) );
    }
    
    Number Number::operator -( signed long long value )
    {
        return operator -( Number( value ) );
    }
    
    Number Number::operator -( unsigned char value )
    {
        return operator -( Number( value ) );
    }
    
    Number Number::operator -( unsigned short value )
    {
        return operator -( Number( value ) );
    }
    
    Number Number::operator -( unsigned int value )
    {
        return operator -( Number( value ) );
    }
    
    Number Number::operator -( unsigned long value )
    {
        return operator -( Number( value ) );
    }
    
    Number Number::operator -( unsigned long long value )
    {
        return operator -( Number( value ) );
    }
    
    Number Number::operator -( float value )
    {
        return operator -( Number( value ) );
    }
    
    Number Number::operator -( double value )
    {
        return operator -( Number( value ) );
    }
    
    Number Number::operator *( const Number & value )
    {
        return Number( *( this ) ) *= value;
    }
    
    Number Number::operator *( CFNumberRef value )
    {
        return operator *( Number( value ) );
    }
    
    Number Number::operator *( signed char value )
    {
        return operator *( Number( value ) );
    }
    
    Number Number::operator *( signed short value )
    {
        return operator *( Number( value ) );
    }
    
    Number Number::operator *( signed int value )
    {
        return operator *( Number( value ) );
    }
    
    Number Number::operator *( signed long value )
    {
        return operator *( Number( value ) );
    }
    
    Number Number::operator *( signed long long value )
    {
        return operator *( Number( value ) );
    }
    
    Number Number::operator *( unsigned char value )
    {
        return operator *( Number( value ) );
    }
    
    Number Number::operator *( unsigned short value )
    {
        return operator *( Number( value ) );
    }
    
    Number Number::operator *( unsigned int value )
    {
        return operator *( Number( value ) );
    }
    
    Number Number::operator *( unsigned long value )
    {
        return operator *( Number( value ) );
    }
    
    Number Number::operator *( unsigned long long value )
    {
        return operator *( Number( value ) );
    }
    
    Number Number::operator *( float value )
    {
        return operator *( Number( value ) );
    }
    
    Number Number::operator *( double value )
    {
        return operator *( Number( value ) );
    }
    
    Number Number::operator /( const Number & value )
    {
        return Number( *( this ) ) /= value;
    }
    
    Number Number::operator /( CFNumberRef value )
    {
        return operator /( Number( value ) );
    }
    
    Number Number::operator /( signed char value )
    {
        return operator /( Number( value ) );
    }
    
    Number Number::operator /( signed short value )
    {
        return operator /( Number( value ) );
    }
    
    Number Number::operator /( signed int value )
    {
        return operator /( Number( value ) );
    }
    
    Number Number::operator /( signed long value )
    {
        return operator /( Number( value ) );
    }
    
    Number Number::operator /( signed long long value )
    {
        return operator /( Number( value ) );
    }
    
    Number Number::operator /( unsigned char value )
    {
        return operator /( Number( value ) );
    }
    
    Number Number::operator /( unsigned short value )
    {
        return operator /( Number( value ) );
    }
    
    Number Number::operator /( unsigned int value )
    {
        return operator /( Number( value ) );
    }
    
    Number Number::operator /( unsigned long value )
    {
        return operator /( Number( value ) );
    }
    
    Number Number::operator /( unsigned long long value )
    {
        return operator /( Number( value ) );
    }
    
    Number Number::operator /( float value )
    {
        return operator /( Number( value ) );
    }
    
    Number Number::operator /( double value )
    {
        return operator /( Number( value ) );
    }
    
    Number Number::operator %( const Number & value )
    {
        return Number( *( this ) ) %= value;
    }
    
    Number Number::operator %( CFNumberRef value )
    {
        return operator %( Number( value ) );
    }
    
    Number Number::operator %( signed char value )
    {
        return operator %( Number( value ) );
    }
    
    Number Number::operator %( signed short value )
    {
        return operator %( Number( value ) );
    }
    
    Number Number::operator %( signed int value )
    {
        return operator %( Number( value ) );
    }
    
    Number Number::operator %( signed long value )
    {
        return operator %( Number( value ) );
    }
    
    Number Number::operator %( signed long long value )
    {
        return operator %( Number( value ) );
    }
    
    Number Number::operator %( unsigned char value )
    {
        return operator %( Number( value ) );
    }
    
    Number Number::operator %( unsigned short value )
    {
        return operator %( Number( value ) );
    }
    
    Number Number::operator %( unsigned int value )
    {
        return operator %( Number( value ) );
    }
    
    Number Number::operator %( unsigned long value )
    {
        return operator %( Number( value ) );
    }
    
    Number Number::operator %( unsigned long long value )
    {
        return operator %( Number( value ) );
    }
    
    Number Number::operator &( const Number & value )
    {
        return Number( *( this ) ) &= value;
    }
    
    Number Number::operator &( CFNumberRef value )
    {
        return operator &( Number( value ) );
    }
    
    Number Number::operator &( signed char value )
    {
        return operator &( Number( value ) );
    }
    
    Number Number::operator &( signed short value )
    {
        return operator &( Number( value ) );
    }
    
    Number Number::operator &( signed int value )
    {
        return operator &( Number( value ) );
    }
    
    Number Number::operator &( signed long value )
    {
        return operator &( Number( value ) );
    }
    
    Number Number::operator &( signed long long value )
    {
        return operator &( Number( value ) );
    }
    
    Number Number::operator &( unsigned char value )
    {
        return operator &( Number( value ) );
    }
    
    Number Number::operator &( unsigned short value )
    {
        return operator &( Number( value ) );
    }
    
    Number Number::operator &( unsigned int value )
    {
        return operator &( Number( value ) );
    }
    
    Number Number::operator &( unsigned long value )
    {
        return operator &( Number( value ) );
    }
    
    Number Number::operator &( unsigned long long value )
    {
        return operator &( Number( value ) );
    }
    
    Number Number::operator |( const Number & value )
    {
        return Number( *( this ) ) |= value;
    }
    
    Number Number::operator |( CFNumberRef value )
    {
        return operator |( Number( value ) );
    }
    
    Number Number::operator |( signed char value )
    {
        return operator |( Number( value ) );
    }
    
    Number Number::operator |( signed short value )
    {
        return operator |( Number( value ) );
    }
    
    Number Number::operator |( signed int value )
    {
        return operator |( Number( value ) );
    }
    
    Number Number::operator |( signed long value )
    {
        return operator |( Number( value ) );
    }
    
    Number Number::operator |( signed long long value )
    {
        return operator |( Number( value ) );
    }
    
    Number Number::operator |( unsigned char value )
    {
        return operator |( Number( value ) );
    }
    
    Number Number::operator |( unsigned short value )
    {
        return operator |( Number( value ) );
    }
    
    Number Number::operator |( unsigned int value )
    {
        return operator |( Number( value ) );
    }
    
    Number Number::operator |( unsigned long value )
    {
        return operator |( Number( value ) );
    }
    
    Number Number::operator |( unsigned long long value )
    {
        return operator |( Number( value ) );
    }
    
    Number Number::operator ^( const Number & value )
    {
        return Number( *( this ) ) ^= value;
    }
    
    Number Number::operator ^( CFNumberRef value )
    {
        return operator ^( Number( value ) );
    }
    
    Number Number::operator ^( signed char value )
    {
        return operator ^( Number( value ) );
    }
    
    Number Number::operator ^( signed short value )
    {
        return operator ^( Number( value ) );
    }
    
    Number Number::operator ^( signed int value )
    {
        return operator ^( Number( value ) );
    }
    
    Number Number::operator ^( signed long value )
    {
        return operator ^( Number( value ) );
    }
    
    Number Number::operator ^( signed long long value )
    {
        return operator ^( Number( value ) );
    }
    
    Number Number::operator ^( unsigned char value )
    {
        return operator ^( Number( value ) );
    }
    
    Number Number::operator ^( unsigned short value )
    {
        return operator ^( Number( value ) );
    }
    
    Number Number::operator ^( unsigned int value )
    {
        return operator ^( Number( value ) );
    }
    
    Number Number::operator ^( unsigned long value )
    {
        return operator ^( Number( value ) );
    }
    
    Number Number::operator ^( unsigned long long value )
    {
        return operator ^( Number( value ) );
    }
    
    Number Number::operator << ( const Number & value )
    {
        return Number( *( this ) ) <<= value;
    }
    
    Number Number::operator << ( CFNumberRef value )
    {
        return operator <<( Number( value ) );
    }
    
    Number Number::operator << ( signed char value )
    {
        return operator <<( Number( value ) );
    }
    
    Number Number::operator << ( signed short value )
    {
        return operator <<( Number( value ) );
    }
    
    Number Number::operator << ( signed int value )
    {
        return operator <<( Number( value ) );
    }
    
    Number Number::operator << ( signed long value )
    {
        return operator <<( Number( value ) );
    }
    
    Number Number::operator << ( signed long long value )
    {
        return operator <<( Number( value ) );
    }
    
    Number Number::operator << ( unsigned char value )
    {
        return operator <<( Number( value ) );
    }
    
    Number Number::operator << ( unsigned short value )
    {
        return operator <<( Number( value ) );
    }
    
    Number Number::operator << ( unsigned int value )
    {
        return operator <<( Number( value ) );
    }
    
    Number Number::operator << ( unsigned long value )
    {
        return operator <<( Number( value ) );
    }
    
    Number Number::operator << ( unsigned long long value )
    {
        return operator <<( Number( value ) );
    }
    
    Number Number::operator >> ( const Number & value )
    {
        return Number( *( this ) ) >>= value;
    }
    
    Number Number::operator >> ( CFNumberRef value )
    {
        return operator >>( Number( value ) );
    }
    
    Number Number::operator >> ( signed char value )
    {
        return operator >>( Number( value ) );
    }
    
    Number Number::operator >> ( signed short value )
    {
        return operator >>( Number( value ) );
    }
    
    Number Number::operator >> ( signed int value )
    {
        return operator >>( Number( value ) );
    }
    
    Number Number::operator >> ( signed long value )
    {
        return operator >>( Number( value ) );
    }
    
    Number Number::operator >> ( signed long long value )
    {
        return operator >>( Number( value ) );
    }
    
    Number Number::operator >> ( unsigned char value )
    {
        return operator >>( Number( value ) );
    }
    
    Number Number::operator >> ( unsigned short value )
    {
        return operator >>( Number( value ) );
    }
    
    Number Number::operator >> ( unsigned int value )
    {
        return operator >>( Number( value ) );
    }
    
    Number Number::operator >> ( unsigned long value )
    {
        return operator >>( Number( value ) );
    }
      
    Number Number::operator >> ( unsigned long long value )
    {
        return operator >>( Number( value ) );
    }
           
    Number::operator signed char () const
    {
        return this->GetSignedCharValue();
    }
    
    Number::operator signed short () const
    {
        return this->GetSignedShortValue();
    }
    
    Number::operator signed int () const
    {
        return this->GetSignedIntValue();
    }

    Number::operator signed long () const
    {
        return this->GetSignedLongValue();
    }

    Number::operator signed long long () const
    {
        return this->GetSignedLongLongValue();
    }

    Number::operator unsigned char () const
    {
        return this->GetUnsignedCharValue();
    }
    
    Number::operator unsigned short () const
    {
        return this->GetUnsignedShortValue();
    }
    
    Number::operator unsigned int () const
    {
        return this->GetUnsignedIntValue();
    }

    Number::operator unsigned long () const
    {
        return this->GetUnsignedLongValue();
    }
    
    Number::operator unsigned long long () const
    {
        return this->GetUnsignedLongLongValue();
    }
    
    Number::operator float () const
    {
        return this->GetFloatValue();
    }
    
    Number::operator double () const
    {
        return this->GetDoubleValue();
    }
    
    CFTypeID Number::GetTypeID() const
    {
        return CFNumberGetTypeID();
    }
    
    CFTypeRef Number::GetCFObject() const
    {
        return this->_cfObject;
    }
    
    bool Number::IsFloatType() const
    {
        if( this->_cfObject == nullptr )
        {
            return false;
        }
        
        return ( CFNumberIsFloatType( this->_cfObject ) ) ? true : false;
    }
    
    signed char Number::GetSignedCharValue() const
    {
        signed char value;
        
        if( this->_cfObject == nullptr )
        {
            return static_cast< signed char >( 0 );
        }
        
        CFNumberGetValue( this->_cfObject, kCFNumberCharType, &value );
        
        return value;
    }
    
    signed short Number::GetSignedShortValue() const
    {
        signed short value;
        
        if( this->_cfObject == nullptr )
        {
            return static_cast< signed short >( 0 );
        }
        
        CFNumberGetValue( this->_cfObject, kCFNumberShortType, &value );
        
        return value;
    }
    
    signed int Number::GetSignedIntValue() const
    {
        signed int value;
        
        if( this->_cfObject == nullptr )
        {
            return static_cast< signed int >( 0 );
        }
        
        CFNumberGetValue( this->_cfObject, kCFNumberIntType, &value );
        
        return value;
    }
    
    signed long Number::GetSignedLongValue() const
    {
        signed long value;
        
        if( this->_cfObject == nullptr )
        {
            return static_cast< signed long >( 0 );
        }
        
        CFNumberGetValue( this->_cfObject, kCFNumberLongType, &value );
        
        return value;
    }
    
    signed long long Number::GetSignedLongLongValue() const
    {
        signed long long value;
        
        if( this->_cfObject == nullptr )
        {
            return static_cast< signed long long >( 0 );
        }
        
        CFNumberGetValue( this->_cfObject, kCFNumberLongLongType, &value );
        
        return value;
    }
    
    unsigned char Number::GetUnsignedCharValue() const
    {
        return static_cast< unsigned char >( this->GetSignedCharValue() );
    }
    
    unsigned short Number::GetUnsignedShortValue() const
    {
        return static_cast< unsigned short >( this->GetSignedShortValue() );
    }
    
    unsigned int Number::GetUnsignedIntValue() const
    {
        return static_cast< unsigned int >( this->GetSignedIntValue() );
    }
    
    unsigned long Number::GetUnsignedLongValue() const
    {
        return static_cast< unsigned long >( this->GetSignedLongValue() );
    }
    
    unsigned long long Number::GetUnsignedLongLongValue() const
    {
        return static_cast< unsigned long long >( this->GetSignedLongLongValue() );
    }
    
    float Number::GetFloatValue() const
    {
        float value;
        
        if( this->_cfObject == nullptr )
        {
            return static_cast< float >( 0 );
        }
        
        CFNumberGetValue( this->_cfObject, kCFNumberFloatType, &value );
        
        return value;
    }
    
    double Number::GetDoubleValue() const
    {
        double value;
        
        if( this->_cfObject == nullptr )
        {
            return static_cast< double >( 0 );
        }
        
        CFNumberGetValue( this->_cfObject, kCFNumberDoubleType, &value );
        
        return value;
    }
    
    void Number::SetSignedCharValue( signed char value )
    {
        if( this->_cfObject != nullptr )
        {
            CFRelease( this->_cfObject );
        }
        
        this->_cfObject = CFNumberCreate( static_cast< CFAllocatorRef >( nullptr ), kCFNumberCharType, &value );
    }
    
    void Number::SetSignedShortValue( signed short value )
    {
        if( this->_cfObject != nullptr )
        {
            CFRelease( this->_cfObject );
        }
        
        this->_cfObject = CFNumberCreate( static_cast< CFAllocatorRef >( nullptr ), kCFNumberShortType, &value );
    }
    
    void Number::SetSignedIntValue( signed int value )
    {
        if( this->_cfObject != nullptr )
        {
            CFRelease( this->_cfObject );
        }
        
        this->_cfObject = CFNumberCreate( static_cast< CFAllocatorRef >( nullptr ), kCFNumberIntType, &value );
    }
    
    void Number::SetSignedLongValue( signed long value )
    {
        if( this->_cfObject != nullptr )
        {
            CFRelease( this->_cfObject );
        }
        
        this->_cfObject = CFNumberCreate( static_cast< CFAllocatorRef >( nullptr ), kCFNumberLongType, &value );
    }
    
    void Number::SetSignedLongLongValue( signed long long value )
    {
        if( this->_cfObject != nullptr )
        {
            CFRelease( this->_cfObject );
        }
        
        this->_cfObject = CFNumberCreate( static_cast< CFAllocatorRef >( nullptr ), kCFNumberLongLongType, &value );
    }
    
    void Number::SetUnsignedCharValue( unsigned char value )
    {
        this->SetSignedCharValue( static_cast< signed char >( value ) );
    }
    
    void Number::SetUnsignedShortValue( unsigned short value )
    {
        this->SetSignedShortValue( static_cast< signed short >( value ) );
    }
    
    void Number::SetUnsignedIntValue( unsigned int value )
    {
        this->SetSignedIntValue( static_cast< signed int >( value ) );
    }
    
    void Number::SetUnsignedLongValue( unsigned long value )
    {
        this->SetSignedLongValue( static_cast< signed long >( value ) );
    }
    
    void Number::SetUnsignedLongLongValue( unsigned long long value )
    {
        this->SetSignedLongLongValue( static_cast< signed long long >( value ) );
    }
    
    void Number::SetFloatValue( float value )
    {
        if( this->_cfObject != nullptr )
        {
            CFRelease( this->_cfObject );
        }
        
        this->_cfObject = CFNumberCreate( static_cast< CFAllocatorRef >( nullptr ), kCFNumberFloatType, &value );
    }
    
    void Number::SetDoubleValue( double value )
    {
        if( this->_cfObject != nullptr )
        {
            CFRelease( this->_cfObject );
        }
        
        this->_cfObject = CFNumberCreate( static_cast< CFAllocatorRef >( nullptr ), kCFNumberDoubleType, &value );
    }
    
    void swap( Number & v1, Number & v2 ) noexcept
    {
        using std::swap;
        
        swap( v1._cfObject, v2._cfObject );
    }
}

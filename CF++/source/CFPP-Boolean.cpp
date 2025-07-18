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
 * @file        CFPP-Boolean.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFBooleanRef wrapper
 */

#include <CF++.hpp>

#ifdef _WIN32

#include <Windows.h>

static bool         __hasCFBoolean   = false;
static CFBooleanRef __cfBooleanTrue  = nullptr;
static CFBooleanRef __cfBooleanFalse = nullptr;

static void __loadCFBoolean()
{
    HMODULE cfModule;

    if( __hasCFBoolean == true )
    {
        return;
    }

    cfModule = GetModuleHandle( L"CoreFoundation.dll" );

    if( cfModule != nullptr )
    {
        __hasCFBoolean   = true;
        __cfBooleanTrue  = *( ( CFBooleanRef * )GetProcAddress( cfModule, "kCFBooleanTrue" ) );
        __cfBooleanFalse = *( ( CFBooleanRef * )GetProcAddress( cfModule, "kCFBooleanFalse" ) );
    }
}

#endif

namespace CF
{
    Boolean::Boolean( const AutoPointer & value ): _cfObject( nullptr )
    {
        bool b;
        
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            b = ( CFBooleanGetValue( static_cast< CFBooleanRef >( value ) ) ) ? true : false;
        }
        else
        {
            b = false;
        }
        
        this->SetValue( b );
    }
    
    Boolean::Boolean( CFTypeRef cfObject ): _cfObject( nullptr )
    {
        bool b;
        
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID()  )
        {
            b = ( CFBooleanGetValue( static_cast< CFBooleanRef >( cfObject ) ) ) ? true : false;
        }
        else
        {
            b = false;
        }
        
        this->SetValue( b );
    }
    
    Boolean::Boolean( CFBooleanRef cfObject ): _cfObject( nullptr )
    {
        bool b;
        
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            b = ( CFBooleanGetValue( cfObject ) ) ? true : false;
        }
        else
        {
            b = false;
        }
        
        this->SetValue( b );
    }
    
    Boolean::Boolean( std::nullptr_t ): Boolean( static_cast< CFTypeRef >( nullptr ) )
    {}
    
    Boolean::Boolean( const AutoPointer & value, bool defaultValueIfNULL ): _cfObject( nullptr )
    {
        bool b;
        
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            b = ( CFBooleanGetValue( static_cast< CFBooleanRef >( value ) ) ) ? true : false;
        }
        else
        {
            b = defaultValueIfNULL;
        }
        
        this->SetValue( b );
    }
    
    Boolean::Boolean( CFTypeRef cfObject, bool defaultValueIfNULL ): _cfObject( nullptr )
    {
        bool b;
        
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            b = ( CFBooleanGetValue( static_cast< CFBooleanRef >( cfObject ) ) ) ? true : false;
        }
        else
        {
            b = defaultValueIfNULL;
        }
        
        this->SetValue( b );
    }
    
    Boolean::Boolean( CFBooleanRef cfObject, bool defaultValueIfNULL ): _cfObject( nullptr )
    {
        bool b;
        
        if( cfObject != nullptr && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            b = ( CFBooleanGetValue( cfObject ) ) ? true : false;
        }
        else
        {
            b = defaultValueIfNULL;
        }
        
        this->SetValue( b );
    }
    
    Boolean::Boolean( bool value ): _cfObject( nullptr )
    {
        this->SetValue( value );
    }
    
    Boolean::Boolean( const Boolean & value ): _cfObject( nullptr )
    {
        this->SetValue( value.GetValue() );
    }
    
    Boolean::Boolean( Boolean && value ) noexcept
    {
        this->_cfObject = value._cfObject;
        value._cfObject = nullptr;
    }
    
    Boolean::~Boolean()
    {
        if( this->_cfObject != nullptr )
        {
            CFRelease( this->_cfObject );
            
            this->_cfObject = nullptr;
        }
    }
    
    Boolean & Boolean::operator =( Boolean value )
    {
        swap( *( this ), value );
        
        return *( this );
    }
    
    Boolean & Boolean::operator =( const AutoPointer & value )
    {
        return operator =( Boolean( value ) );
    }
    
    Boolean & Boolean::operator =( CFTypeRef value )
    {
        return operator =( Boolean( value ) );
    }
    
    Boolean & Boolean::operator =( CFBooleanRef value )
    {
        return operator =( Boolean( value ) );
    }
    
    Boolean & Boolean::operator =( std::nullptr_t )
    {
        return operator =( Boolean( nullptr ) );
    }
    
    Boolean & Boolean::operator =( bool value )
    {
        return operator =( Boolean( value ) );
    }
    
    bool Boolean::operator == ( const Boolean & value ) const
    {
        return this->GetValue() == value.GetValue();
    }
    
    bool Boolean::operator == ( bool value ) const
    {
        return operator ==( Boolean( value ) );
    }
    
    bool Boolean::operator == ( CFTypeRef value ) const
    {
        bool b;

        if( value == nullptr || CFGetTypeID( value ) != this->GetTypeID() )
        {
            return false;
        }
        
        b = ( CFBooleanGetValue( static_cast< CFBooleanRef >( value ) ) ) ? true : false;

        return this->GetValue() == b;
    }
    
    bool Boolean::operator == ( CFBooleanRef value ) const
    {
        return operator ==( static_cast< CFTypeRef >( value ) );
    }
            
    bool Boolean::operator != ( const Boolean & value ) const
    {
        return !operator ==( value );
    }
    
    bool Boolean::operator != ( bool value ) const
    {
        return !operator ==( value );
    }
    
    bool Boolean::operator != ( CFTypeRef value ) const
    {
        return !operator ==( value );
    }
    
    bool Boolean::operator != ( CFBooleanRef value ) const
    {
        return !operator ==( value );
    }
    
    Boolean::operator bool () const
    {
        return this->GetValue();
    }
    
    CFTypeID Boolean::GetTypeID() const
    {
        return CFBooleanGetTypeID();
    }
    
    CFTypeRef Boolean::GetCFObject() const
    {
        return static_cast< CFTypeRef >( this->_cfObject );
    }
            
    bool Boolean::GetValue() const
    {
        if( this->_cfObject == nullptr )
        {
            return false;
        }
        
        return ( CFBooleanGetValue( this->_cfObject ) ) ? true : false;
    }
    
    void Boolean::SetValue( bool value )
    {
        if( this->_cfObject != nullptr )
        {
            CFRelease( this->_cfObject );
        }
        
        #ifdef _WIN32

        __loadCFBoolean();

        this->_cfObject = static_cast< CFBooleanRef >( CFRetain( ( value == true ) ? __cfBooleanTrue : __cfBooleanFalse ) );

        #else
        
        this->_cfObject = static_cast< CFBooleanRef >( CFRetain( ( value == true ) ? kCFBooleanTrue : kCFBooleanFalse ) );
        
        #endif
    }
    
    void swap( Boolean & v1, Boolean & v2 ) noexcept
    {
        using std::swap;
        
        swap( v1._cfObject, v2._cfObject );
    }
}

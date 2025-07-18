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
 * @header      CFPP-Number.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFNumberRef wrapper
 */

#ifndef CFPP_NUMBER_HPP
#define CFPP_NUMBER_HPP

#include <stdint.h>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++11-long-long" /* Do not warn about long long in C++98 */
#endif

namespace CF
{
    class CFPP_EXPORT Number: public PropertyListType< Number >
    {
        public:

            Number();
            Number( const AutoPointer & value );
            Number( CFTypeRef cfObject );
            Number( CFNumberRef cfObject );
            Number( std::nullptr_t );
            Number( const AutoPointer & value, signed char defaultValueIfNULL );
            Number( const AutoPointer & value, signed short defaultValueIfNULL );
            Number( const AutoPointer & value, signed int defaultValueIfNULL );
            Number( const AutoPointer & value, signed long defaultValueIfNULL );
            Number( const AutoPointer & value, signed long long defaultValueIfNULL );
            Number( const AutoPointer & value, unsigned char defaultValueIfNULL );
            Number( const AutoPointer & value, unsigned short defaultValueIfNULL );
            Number( const AutoPointer & value, unsigned int defaultValueIfNULL );
            Number( const AutoPointer & value, unsigned long defaultValueIfNULL );
            Number( const AutoPointer & value, unsigned long long defaultValueIfNULL );
            Number( const AutoPointer & value, float defaultValueIfNULL );
            Number( const AutoPointer & value, double defaultValueIfNULL );
            Number( CFTypeRef cfObject, signed char defaultValueIfNULL );
            Number( CFTypeRef cfObject, signed short defaultValueIfNULL );
            Number( CFTypeRef cfObject, signed int defaultValueIfNULL );
            Number( CFTypeRef cfObject, signed long defaultValueIfNULL );
            Number( CFTypeRef cfObject, signed long long defaultValueIfNULL );
            Number( CFTypeRef cfObject, unsigned char defaultValueIfNULL );
            Number( CFTypeRef cfObject, unsigned short defaultValueIfNULL );
            Number( CFTypeRef cfObject, unsigned int defaultValueIfNULL );
            Number( CFTypeRef cfObject, unsigned long defaultValueIfNULL );
            Number( CFTypeRef cfObject, unsigned long long defaultValueIfNULL );
            Number( CFTypeRef cfObject, float defaultValueIfNULL );
            Number( CFTypeRef cfObject, double defaultValueIfNULL );
            Number( CFNumberRef cfObject, signed char defaultValueIfNULL );
            Number( CFNumberRef cfObject, signed short defaultValueIfNULL );
            Number( CFNumberRef cfObject, signed int defaultValueIfNULL );
            Number( CFNumberRef cfObject, signed long defaultValueIfNULL );
            Number( CFNumberRef cfObject, signed long long defaultValueIfNULL );
            Number( CFNumberRef cfObject, unsigned char defaultValueIfNULL );
            Number( CFNumberRef cfObject, unsigned short defaultValueIfNULL );
            Number( CFNumberRef cfObject, unsigned int defaultValueIfNULL );
            Number( CFNumberRef cfObject, unsigned long defaultValueIfNULL );
            Number( CFNumberRef cfObject, unsigned long long defaultValueIfNULL );
            Number( CFNumberRef cfObject, float defaultValueIfNULL );
            Number( CFNumberRef cfObject, double defaultValueIfNULL );
            Number( const Number & value );
            Number( signed char value );
            Number( signed short value );
            Number( signed int value );
            Number( signed long value );
            Number( signed long long value );
            Number( unsigned char value );
            Number( unsigned short value );
            Number( unsigned int value );
            Number( unsigned long value );
            Number( unsigned long long value );
            Number( float value );
            Number( double value );
            Number( Number && value ) noexcept;
            
            ~Number() override;
            
            Number & operator =( Number value );
            Number & operator =( const AutoPointer & value );
            Number & operator =( CFTypeRef value );
            Number & operator =( CFNumberRef value );
            Number & operator =( std::nullptr_t value );
            Number & operator =( signed char value );
            Number & operator =( signed short value );
            Number & operator =( signed int value );
            Number & operator =( signed long value );
            Number & operator =( signed long long value );
            Number & operator =( unsigned char value );
            Number & operator =( unsigned short value );
            Number & operator =( unsigned int value );
            Number & operator =( unsigned long value );
            Number & operator =( unsigned long long value );
            Number & operator =( float value );
            Number & operator =( double value );
            
            bool operator == ( const Number & value )     const;
            bool operator == ( CFTypeRef value )          const;
            bool operator == ( CFNumberRef value )        const;
            bool operator == ( signed char value )        const;
            bool operator == ( signed short value )       const;
            bool operator == ( signed int value )         const;
            bool operator == ( signed long value )        const;
            bool operator == ( signed long long value )   const;
            bool operator == ( unsigned char value )      const;
            bool operator == ( unsigned short value )     const;
            bool operator == ( unsigned int value )       const;
            bool operator == ( unsigned long value )      const;
            bool operator == ( unsigned long long value ) const;
            bool operator == ( float value )              const;
            bool operator == ( double value )             const;
            
            bool operator != ( const Number & value )     const;
            bool operator != ( CFTypeRef value )          const;
            bool operator != ( CFNumberRef value )        const;
            bool operator != ( signed char value )        const;
            bool operator != ( signed short value )       const;
            bool operator != ( signed int value )         const;
            bool operator != ( signed long value )        const;
            bool operator != ( signed long long value )   const;
            bool operator != ( unsigned char value )      const;
            bool operator != ( unsigned short value )     const;
            bool operator != ( unsigned int value )       const;
            bool operator != ( unsigned long value )      const;
            bool operator != ( unsigned long long value ) const;
            bool operator != ( float value )              const;
            bool operator != ( double value )             const;
            
            bool operator >= ( const Number & value )     const;
            bool operator >= ( CFTypeRef value )          const;
            bool operator >= ( CFNumberRef value )        const;
            bool operator >= ( signed char value )        const;
            bool operator >= ( signed short value )       const;
            bool operator >= ( signed int value )         const;
            bool operator >= ( signed long value )        const;
            bool operator >= ( signed long long value )   const;
            bool operator >= ( unsigned char value )      const;
            bool operator >= ( unsigned short value )     const;
            bool operator >= ( unsigned int value )       const;
            bool operator >= ( unsigned long value )      const;
            bool operator >= ( unsigned long long value ) const;
            bool operator >= ( float value )              const;
            bool operator >= ( double value )             const;
            
            bool operator <= ( const Number & value )     const;
            bool operator <= ( CFTypeRef value )          const;
            bool operator <= ( CFNumberRef value )        const;
            bool operator <= ( signed char value )        const;
            bool operator <= ( signed short value )       const;
            bool operator <= ( signed int value )         const;
            bool operator <= ( signed long value )        const;
            bool operator <= ( signed long long value )   const;
            bool operator <= ( unsigned char value )      const;
            bool operator <= ( unsigned short value )     const;
            bool operator <= ( unsigned int value )       const;
            bool operator <= ( unsigned long value )      const;
            bool operator <= ( unsigned long long value ) const;
            bool operator <= ( float value )              const;
            bool operator <= ( double value )             const;
            
            bool operator >( const Number & value )     const;
            bool operator >( CFTypeRef value )          const;
            bool operator >( CFNumberRef value )        const;
            bool operator >( signed char value )        const;
            bool operator >( signed short value )       const;
            bool operator >( signed int value )         const;
            bool operator >( signed long value )        const;
            bool operator >( signed long long value )   const;
            bool operator >( unsigned char value )      const;
            bool operator >( unsigned short value )     const;
            bool operator >( unsigned int value )       const;
            bool operator >( unsigned long value )      const;
            bool operator >( unsigned long long value ) const;
            bool operator >( float value )              const;
            bool operator >( double value )             const;
            
            bool operator <( const Number & value )     const;
            bool operator <( CFTypeRef value )          const;
            bool operator <( CFNumberRef value )        const;
            bool operator <( signed char value )        const;
            bool operator <( signed short value )       const;
            bool operator <( signed int value )         const;
            bool operator <( signed long value )        const;
            bool operator <( signed long long value )   const;
            bool operator <( unsigned char value )      const;
            bool operator <( unsigned short value )     const;
            bool operator <( unsigned int value )       const;
            bool operator <( unsigned long value )      const;
            bool operator <( unsigned long long value ) const;
            bool operator <( float value )              const;
            bool operator <( double value )             const;
            
            bool operator && ( const Number & value )     const;
            bool operator && ( CFTypeRef value )          const;
            bool operator && ( CFNumberRef value )        const;
            bool operator && ( signed char value )        const;
            bool operator && ( signed short value )       const;
            bool operator && ( signed int value )         const;
            bool operator && ( signed long value )        const;
            bool operator && ( signed long long value )   const;
            bool operator && ( unsigned char value )      const;
            bool operator && ( unsigned short value )     const;
            bool operator && ( unsigned int value )       const;
            bool operator && ( unsigned long value )      const;
            bool operator && ( unsigned long long value ) const;
            bool operator && ( float value )              const;
            bool operator && ( double value )             const;
            
            bool operator || ( const Number & value )     const;
            bool operator || ( CFTypeRef value )          const;
            bool operator || ( CFNumberRef value )        const;
            bool operator || ( signed char value )        const;
            bool operator || ( signed short value )       const;
            bool operator || ( signed int value )         const;
            bool operator || ( signed long value )        const;
            bool operator || ( signed long long value )   const;
            bool operator || ( unsigned char value )      const;
            bool operator || ( unsigned short value )     const;
            bool operator || ( unsigned int value )       const;
            bool operator || ( unsigned long value )      const;
            bool operator || ( unsigned long long value ) const;
            bool operator || ( float value )              const;
            bool operator || ( double value )             const;
            
            Number & operator ~();
            Number & operator !();
            Number & operator ++ ();
            Number   operator ++ ( int );
            Number & operator -- ();
            Number   operator -- ( int );
            
            Number & operator += ( const Number & value );
            Number & operator += ( CFNumberRef value );
            Number & operator += ( signed char value );
            Number & operator += ( signed short value );
            Number & operator += ( signed int value );
            Number & operator += ( signed long value );
            Number & operator += ( signed long long value );
            Number & operator += ( unsigned char value );
            Number & operator += ( unsigned short value );
            Number & operator += ( unsigned int value );
            Number & operator += ( unsigned long value );
            Number & operator += ( unsigned long long value );
            Number & operator += ( float value );
            Number & operator += ( double value );
            
            Number & operator -= ( const Number & value );
            Number & operator -= ( CFNumberRef value );
            Number & operator -= ( signed char value );
            Number & operator -= ( signed short value );
            Number & operator -= ( signed int value );
            Number & operator -= ( signed long value );
            Number & operator -= ( signed long long value );
            Number & operator -= ( unsigned char value );
            Number & operator -= ( unsigned short value );
            Number & operator -= ( unsigned int value );
            Number & operator -= ( unsigned long value );
            Number & operator -= ( unsigned long long value );
            Number & operator -= ( float value );
            Number & operator -= ( double value );
            
            Number & operator *= ( const Number & value );
            Number & operator *= ( CFNumberRef value );
            Number & operator *= ( signed char value );
            Number & operator *= ( signed short value );
            Number & operator *= ( signed int value );
            Number & operator *= ( signed long value );
            Number & operator *= ( signed long long value );
            Number & operator *= ( unsigned char value );
            Number & operator *= ( unsigned short value );
            Number & operator *= ( unsigned int value );
            Number & operator *= ( unsigned long value );
            Number & operator *= ( unsigned long long value );
            Number & operator *= ( float value );
            Number & operator *= ( double value );
            
            Number & operator /= ( const Number & value );
            Number & operator /= ( CFNumberRef value );
            Number & operator /= ( signed char value );
            Number & operator /= ( signed short value );
            Number & operator /= ( signed int value );
            Number & operator /= ( signed long value );
            Number & operator /= ( signed long long value );
            Number & operator /= ( unsigned char value );
            Number & operator /= ( unsigned short value );
            Number & operator /= ( unsigned int value );
            Number & operator /= ( unsigned long value );
            Number & operator /= ( unsigned long long value );
            Number & operator /= ( float value );
            Number & operator /= ( double value );
            
            Number & operator |= ( const Number & value );
            Number & operator |= ( CFNumberRef value );
            Number & operator |= ( signed char value );
            Number & operator |= ( signed short value );
            Number & operator |= ( signed int value );
            Number & operator |= ( signed long value );
            Number & operator |= ( signed long long value );
            Number & operator |= ( unsigned char value );
            Number & operator |= ( unsigned short value );
            Number & operator |= ( unsigned int value );
            Number & operator |= ( unsigned long value );
            Number & operator |= ( unsigned long long value );
            
            Number & operator &= ( const Number & value );
            Number & operator &= ( CFNumberRef value );
            Number & operator &= ( signed char value );
            Number & operator &= ( signed short value );
            Number & operator &= ( signed int value );
            Number & operator &= ( signed long value );
            Number & operator &= ( signed long long value );
            Number & operator &= ( unsigned char value );
            Number & operator &= ( unsigned short value );
            Number & operator &= ( unsigned int value );
            Number & operator &= ( unsigned long value );
            Number & operator &= ( unsigned long long value );
            
            Number & operator %= ( const Number & value );
            Number & operator %= ( CFNumberRef value );
            Number & operator %= ( signed char value );
            Number & operator %= ( signed short value );
            Number & operator %= ( signed int value );
            Number & operator %= ( signed long value );
            Number & operator %= ( signed long long value );
            Number & operator %= ( unsigned char value );
            Number & operator %= ( unsigned short value );
            Number & operator %= ( unsigned int value );
            Number & operator %= ( unsigned long value );
            Number & operator %= ( unsigned long long value );
            
            Number & operator ^= ( const Number & value );
            Number & operator ^= ( CFNumberRef value );
            Number & operator ^= ( signed char value );
            Number & operator ^= ( signed short value );
            Number & operator ^= ( signed int value );
            Number & operator ^= ( signed long value );
            Number & operator ^= ( signed long long value );
            Number & operator ^= ( unsigned char value );
            Number & operator ^= ( unsigned short value );
            Number & operator ^= ( unsigned int value );
            Number & operator ^= ( unsigned long value );
            Number & operator ^= ( unsigned long long value );
            
            Number & operator <<= ( const Number & value );
            Number & operator <<= ( CFNumberRef value );
            Number & operator <<= ( signed char value );
            Number & operator <<= ( signed short value );
            Number & operator <<= ( signed int value );
            Number & operator <<= ( signed long value );
            Number & operator <<= ( signed long long value );
            Number & operator <<= ( unsigned char value );
            Number & operator <<= ( unsigned short value );
            Number & operator <<= ( unsigned int value );
            Number & operator <<= ( unsigned long value );
            Number & operator <<= ( unsigned long long value );
            
            Number & operator >>= ( const Number & value );
            Number & operator >>= ( CFNumberRef value );
            Number & operator >>= ( signed char value );
            Number & operator >>= ( signed short value );
            Number & operator >>= ( signed int value );
            Number & operator >>= ( signed long value );
            Number & operator >>= ( signed long long value );
            Number & operator >>= ( unsigned char value );
            Number & operator >>= ( unsigned short value );
            Number & operator >>= ( unsigned int value );
            Number & operator >>= ( unsigned long value );
            Number & operator >>= ( unsigned long long value );
            
            Number operator +( const Number & value );
            Number operator +( CFNumberRef value );
            Number operator +( signed char value );
            Number operator +( signed short value );
            Number operator +( signed int value );
            Number operator +( signed long value );
            Number operator +( signed long long value );
            Number operator +( unsigned char value );
            Number operator +( unsigned short value );
            Number operator +( unsigned int value );
            Number operator +( unsigned long value );
            Number operator +( unsigned long long value );
            Number operator +( float value );
            Number operator +( double value );
            
            Number operator -( const Number & value );
            Number operator -( CFNumberRef value );
            Number operator -( signed char value );
            Number operator -( signed short value );
            Number operator -( signed int value );
            Number operator -( signed long value );
            Number operator -( signed long long value );
            Number operator -( unsigned char value );
            Number operator -( unsigned short value );
            Number operator -( unsigned int value );
            Number operator -( unsigned long value );
            Number operator -( unsigned long long value );
            Number operator -( float value );
            Number operator -( double value );
            
            Number operator *( const Number & value );
            Number operator *( CFNumberRef value );
            Number operator *( signed char value );
            Number operator *( signed short value );
            Number operator *( signed int value );
            Number operator *( signed long value );
            Number operator *( signed long long value );
            Number operator *( unsigned char value );
            Number operator *( unsigned short value );
            Number operator *( unsigned int value );
            Number operator *( unsigned long value );
            Number operator *( unsigned long long value );
            Number operator *( float value );
            Number operator *( double value );
            
            Number operator /( const Number & value );
            Number operator /( CFNumberRef value );
            Number operator /( signed char value );
            Number operator /( signed short value );
            Number operator /( signed int value );
            Number operator /( signed long value );
            Number operator /( signed long long value );
            Number operator /( unsigned char value );
            Number operator /( unsigned short value );
            Number operator /( unsigned int value );
            Number operator /( unsigned long value );
            Number operator /( unsigned long long value );
            Number operator /( float value );
            Number operator /( double value );
            
            Number operator %( const Number & value );
            Number operator %( CFNumberRef value );
            Number operator %( signed char value );
            Number operator %( signed short value );
            Number operator %( signed int value );
            Number operator %( signed long value );
            Number operator %( signed long long value );
            Number operator %( unsigned char value );
            Number operator %( unsigned short value );
            Number operator %( unsigned int value );
            Number operator %( unsigned long value );
            Number operator %( unsigned long long value );
        
            Number operator &( const Number & value );
            Number operator &( CFNumberRef value );
            Number operator &( signed char value );
            Number operator &( signed short value );
            Number operator &( signed int value );
            Number operator &( signed long value );
            Number operator &( signed long long value );
            Number operator &( unsigned char value );
            Number operator &( unsigned short value );
            Number operator &( unsigned int value );
            Number operator &( unsigned long value );
            Number operator &( unsigned long long value );
            
            Number operator |( const Number & value );
            Number operator |( CFNumberRef value );
            Number operator |( signed char value );
            Number operator |( signed short value );
            Number operator |( signed int value );
            Number operator |( signed long value );
            Number operator |( signed long long value );
            Number operator |( unsigned char value );
            Number operator |( unsigned short value );
            Number operator |( unsigned int value );
            Number operator |( unsigned long value );
            Number operator |( unsigned long long value );
            
            Number operator ^( const Number & value );
            Number operator ^( CFNumberRef value );
            Number operator ^( signed char value );
            Number operator ^( signed short value );
            Number operator ^( signed int value );
            Number operator ^( signed long value );
            Number operator ^( signed long long value );
            Number operator ^( unsigned char value );
            Number operator ^( unsigned short value );
            Number operator ^( unsigned int value );
            Number operator ^( unsigned long value );
            Number operator ^( unsigned long long value );
        
            Number operator << ( const Number & value );
            Number operator << ( CFNumberRef value );
            Number operator << ( signed char value );
            Number operator << ( signed short value );
            Number operator << ( signed int value );
            Number operator << ( signed long value );
            Number operator << ( signed long long value );
            Number operator << ( unsigned char value );
            Number operator << ( unsigned short value );
            Number operator << ( unsigned int value );
            Number operator << ( unsigned long value );
            Number operator << ( unsigned long long value );
            
            Number operator >> ( const Number & value );
            Number operator >> ( CFNumberRef value );
            Number operator >> ( signed char value );
            Number operator >> ( signed short value );
            Number operator >> ( signed int value );
            Number operator >> ( signed long value );
            Number operator >> ( signed long long value );
            Number operator >> ( unsigned char value );
            Number operator >> ( unsigned short value );
            Number operator >> ( unsigned int value );
            Number operator >> ( unsigned long value );
            Number operator >> ( unsigned long long value );
            
            operator signed char        () const;
            operator signed short       () const;
            operator signed int         () const;
            operator signed long        () const;
            operator signed long long   () const;
            operator unsigned char      () const;
            operator unsigned short     () const;
            operator unsigned int       () const;
            operator unsigned long      () const;
            operator unsigned long long () const;
            operator float              () const;
            operator double             () const;
            
            CFTypeID  GetTypeID()   const override;
            CFTypeRef GetCFObject() const override;
            
            bool IsFloatType() const;
            
            signed char         GetSignedCharValue()       const;
            signed short        GetSignedShortValue()      const;
            signed int          GetSignedIntValue()        const;
            signed long         GetSignedLongValue()       const;
            signed long long    GetSignedLongLongValue()   const;
            unsigned char       GetUnsignedCharValue()     const;
            unsigned short      GetUnsignedShortValue()    const;
            unsigned int        GetUnsignedIntValue()      const;
            unsigned long       GetUnsignedLongValue()     const;
            unsigned long long  GetUnsignedLongLongValue() const;
            float               GetFloatValue()            const;
            double              GetDoubleValue()           const;
            
            void SetSignedCharValue( signed char value );
            void SetSignedShortValue( signed short value );
            void SetSignedIntValue( signed int value );
            void SetSignedLongValue( signed long value );
            void SetSignedLongLongValue( signed long long value );
            void SetUnsignedCharValue( unsigned char value );
            void SetUnsignedShortValue( unsigned short value );
            void SetUnsignedIntValue( unsigned int value );
            void SetUnsignedLongValue( unsigned long value );
            void SetUnsignedLongLongValue( unsigned long long value );
            void SetFloatValue( float value );
            void SetDoubleValue( double value );
            
            friend void swap( Number & v1, Number & v2 ) noexcept;
            
        private:
            
            CFNumberRef _cfObject;
    };
}

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif /* CFPP_NUMBER_HPP */

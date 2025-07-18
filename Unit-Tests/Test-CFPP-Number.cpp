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
 * @file        Test-CFPP-Number.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    Unit tests for CF::Number
 */

#include <CF++.hpp>

#define XSTEST_GTEST_COMPAT
#include <XSTest/XSTest.hpp>

#ifdef __clang__
#pragma clang diagnostic ignored "-Wself-assign-overloaded"
#endif

static bool FloatIsEqual( Float32 x, Float32 y );
static bool FloatIsEqual( Float64 x, Float64 y );

static bool FloatIsEqual( Float32 x, Float32 y )
{
    return fabsf( x - y ) < FLT_EPSILON;
}

static bool FloatIsEqual( Float64 x, Float64 y )
{
    return fabs( x - y ) < DBL_EPSILON;
}

TEST( CFPP_Number, CTOR )
{
    CF::Number n;
    
    ASSERT_TRUE( n.IsValid() );
    ASSERT_TRUE( n == 0 );
    ASSERT_TRUE( n.GetCFObject() != nullptr );
}

TEST( CFPP_Number, CTOR_AutoPointer )
{
    int i = 0;
    
    {
        CF::Number n1( CF::AutoPointer( CFNumberCreate( nullptr, kCFNumberIntType, &i ) ) );
        CF::Number n2( CF::AutoPointer( CFUUIDCreate( nullptr ) ) );
        CF::Number n3( CF::AutoPointer( nullptr ) );
        
        ASSERT_TRUE(  n1.IsValid() );
        ASSERT_FALSE( n2.IsValid() );
        ASSERT_FALSE( n3.IsValid() );
    }
}

TEST( CFPP_Number, CTOR_CFType )
{
    CF::Number n1( static_cast< CFTypeRef >( CF::Number( 42 ).GetCFObject() ) );
    CF::Number n2( static_cast< CFTypeRef >( nullptr ) );
    
    ASSERT_TRUE(  n1.IsValid() );
    ASSERT_FALSE( n2.IsValid() );
    
    ASSERT_TRUE( n1 == 42 );
    ASSERT_TRUE( n2 == 0 );
    
    ASSERT_TRUE( n1.GetCFObject() != nullptr );
    ASSERT_TRUE( n2.GetCFObject() == nullptr );
}

TEST( CFPP_Number, CTOR_CFNumber )
{
    CF::Number n1( static_cast< CFNumberRef >( CF::Number( 42 ).GetCFObject() ) );
    CF::Number n2( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_TRUE(  n1.IsValid() );
    ASSERT_FALSE( n2.IsValid() );
    
    ASSERT_TRUE( n1 == 42 );
    ASSERT_TRUE( n2 == 0 );
    
    ASSERT_TRUE( n1.GetCFObject() != nullptr );
    ASSERT_TRUE( n2.GetCFObject() == nullptr );
}

TEST( CFPP_Number, CTOR_NullPointer )
{
    CF::Number n( nullptr );
    
    ASSERT_FALSE( n.IsValid() );
}

template< typename T >
void TMPL_CFPP_Number_CTOR_AutoPointer_T()
{
    int i =  1;
    T   v = 42;
    
    {
        CF::Number n1( CF::AutoPointer( CFNumberCreate( nullptr, kCFNumberIntType, &i ) ), v );
        CF::Number n2( CF::AutoPointer( CFUUIDCreate( nullptr ) ), v );
        CF::Number n3( CF::AutoPointer( nullptr ), v );
        
        ASSERT_TRUE( n1.IsValid() );
        ASSERT_TRUE( n2.IsValid() );
        ASSERT_TRUE( n3.IsValid() );
        
        ASSERT_TRUE( n1 == i );
        ASSERT_TRUE( n2 == v );
        ASSERT_TRUE( n3 == v );
    }
}

TEST( CFPP_Number, CTOR_AutoPointer_T )
{
    TMPL_CFPP_Number_CTOR_AutoPointer_T< SInt8 >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< SInt16 >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< SInt32 >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< SInt64 >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< UInt8 >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< UInt16 >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< UInt32 >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< UInt64 >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< Float32 >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< Float64 >();
    
    TMPL_CFPP_Number_CTOR_AutoPointer_T< signed char >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< signed short >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< signed int >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< signed long >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< signed long long >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< unsigned char >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< unsigned short >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< unsigned int >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< unsigned long >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< unsigned long long >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< float >();
    TMPL_CFPP_Number_CTOR_AutoPointer_T< double >();
}

template< typename T >
void TMPL_CFPP_Number_CTOR_CFType_T()
{
    CF::Number n1( static_cast< CFTypeRef >( CF::Number( 42 ).GetCFObject() ), static_cast< T >( 43 ) );
    CF::Number n2( static_cast< CFTypeRef >( nullptr ),                           static_cast< T >( 43 ) );
    
    ASSERT_TRUE( n1.IsValid() );
    ASSERT_TRUE( n2.IsValid() );
    
    ASSERT_TRUE( n1 == 42 );
    ASSERT_TRUE( n2 == 43 );
}

TEST( CFPP_Number, CTOR_CFType_T )
{
    TMPL_CFPP_Number_CTOR_CFType_T< SInt8 >();
    TMPL_CFPP_Number_CTOR_CFType_T< SInt16 >();
    TMPL_CFPP_Number_CTOR_CFType_T< SInt32 >();
    TMPL_CFPP_Number_CTOR_CFType_T< SInt64 >();
    TMPL_CFPP_Number_CTOR_CFType_T< UInt8 >();
    TMPL_CFPP_Number_CTOR_CFType_T< UInt16 >();
    TMPL_CFPP_Number_CTOR_CFType_T< UInt32 >();
    TMPL_CFPP_Number_CTOR_CFType_T< UInt64 >();
    TMPL_CFPP_Number_CTOR_CFType_T< Float32 >();
    TMPL_CFPP_Number_CTOR_CFType_T< Float64 >();
    
    TMPL_CFPP_Number_CTOR_CFType_T< signed char >();
    TMPL_CFPP_Number_CTOR_CFType_T< signed short >();
    TMPL_CFPP_Number_CTOR_CFType_T< signed int >();
    TMPL_CFPP_Number_CTOR_CFType_T< signed long >();
    TMPL_CFPP_Number_CTOR_CFType_T< signed long long >();
    TMPL_CFPP_Number_CTOR_CFType_T< unsigned char >();
    TMPL_CFPP_Number_CTOR_CFType_T< unsigned short >();
    TMPL_CFPP_Number_CTOR_CFType_T< unsigned int >();
    TMPL_CFPP_Number_CTOR_CFType_T< unsigned long >();
    TMPL_CFPP_Number_CTOR_CFType_T< unsigned long long >();
    TMPL_CFPP_Number_CTOR_CFType_T< float >();
    TMPL_CFPP_Number_CTOR_CFType_T< double >();
}

template< typename T >
void TMPL_CFPP_Number_CTOR_CFNumber_T()
{
    CF::Number n1( static_cast< CFNumberRef >( CF::Number( 42 ).GetCFObject() ), static_cast< T >( 43 ) );
    CF::Number n2( static_cast< CFNumberRef >( nullptr ),                           static_cast< T >( 43 ) );
    
    ASSERT_TRUE( n1.IsValid() );
    ASSERT_TRUE( n2.IsValid() );
    
    ASSERT_TRUE( n1 == 42 );
    ASSERT_TRUE( n2 == 43 );
}

TEST( CFPP_Number, CTOR_CFNumber_T )
{
    TMPL_CFPP_Number_CTOR_CFNumber_T< SInt8 >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< SInt16 >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< SInt32 >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< SInt64 >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< UInt8 >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< UInt16 >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< UInt32 >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< UInt64 >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< Float32 >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< Float64 >();
    
    TMPL_CFPP_Number_CTOR_CFNumber_T< signed char >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< signed short >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< signed int >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< signed long >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< signed long long >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< unsigned char >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< unsigned short >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< unsigned int >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< unsigned long >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< unsigned long long >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< float >();
    TMPL_CFPP_Number_CTOR_CFNumber_T< double >();
}

template< typename T >
void TMPL_CFPP_Number_CTOR_T()
{
    CF::Number n( static_cast< T >( 42 ) );
    
    ASSERT_TRUE( n == 42 );
}

TEST( CFPP_Number, CTOR_T )
{
    TMPL_CFPP_Number_CTOR_T< SInt8 >();
    TMPL_CFPP_Number_CTOR_T< SInt16 >();
    TMPL_CFPP_Number_CTOR_T< SInt32 >();
    TMPL_CFPP_Number_CTOR_T< SInt64 >();
    TMPL_CFPP_Number_CTOR_T< UInt8 >();
    TMPL_CFPP_Number_CTOR_T< UInt16 >();
    TMPL_CFPP_Number_CTOR_T< UInt32 >();
    TMPL_CFPP_Number_CTOR_T< UInt64 >();
    TMPL_CFPP_Number_CTOR_T< Float32 >();
    TMPL_CFPP_Number_CTOR_T< Float64 >();
    
    TMPL_CFPP_Number_CTOR_T< signed char >();
    TMPL_CFPP_Number_CTOR_T< signed short >();
    TMPL_CFPP_Number_CTOR_T< signed int >();
    TMPL_CFPP_Number_CTOR_T< signed long >();
    TMPL_CFPP_Number_CTOR_T< signed long long >();
    TMPL_CFPP_Number_CTOR_T< unsigned char >();
    TMPL_CFPP_Number_CTOR_T< unsigned short >();
    TMPL_CFPP_Number_CTOR_T< unsigned int >();
    TMPL_CFPP_Number_CTOR_T< unsigned long >();
    TMPL_CFPP_Number_CTOR_T< unsigned long long >();
    TMPL_CFPP_Number_CTOR_T< float >();
    TMPL_CFPP_Number_CTOR_T< double >();
}

TEST( CFPP_Number, CCTOR )
{
    CF::Number n1( 42 );
    CF::Number n2( n1 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    CF::Number n4( n3 );
    
    ASSERT_TRUE( n1.IsValid() );
    ASSERT_TRUE( n2.IsValid() );
    
    ASSERT_TRUE( n1 == 42 );
    ASSERT_TRUE( n2 == 42 ); 
    
    ASSERT_FALSE( n3.IsValid() );
    ASSERT_FALSE( n4.IsValid() );
}

TEST( CFPP_Number, MCTOR )
{
    CF::Number n1( 42 );
    CF::Number n2( std::move( n1 ) );
    
    ASSERT_FALSE( n1.IsValid() );
    ASSERT_TRUE(  n2.IsValid() );
    
    ASSERT_TRUE( n2 == 42 );
}

TEST( CFPP_Number, OperatorAssignNumber )
{
    CF::Number n1;
    CF::Number n2( 1 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_TRUE( n1 == 0 );
    ASSERT_TRUE( n2 == 1 );
    ASSERT_FALSE( n3.IsValid() );
    
    n1 = n2;
    
    ASSERT_TRUE( n1 == 1 );
    
    n1 = n3;
    
    ASSERT_FALSE( n1.IsValid() );
    ASSERT_TRUE( n1 == 0 );
    
    n1 = n2;
    
    ASSERT_TRUE( n1.IsValid() );
    ASSERT_TRUE( n1 == 1 );
}

TEST( CFPP_Number, OperatorAssignAutoPointer )
{
    int i = 0;
    
    {
        CF::Number n1( static_cast< CFTypeRef >( nullptr ) );
        CF::Number n2;
        CF::Number n3;
        
        ASSERT_FALSE( n1.IsValid() );
        ASSERT_TRUE(  n2.IsValid() );
        ASSERT_TRUE(  n3.IsValid() );
        
        n1 = CF::AutoPointer( CFNumberCreate( nullptr, kCFNumberIntType, &i ) );
        n2 = CF::AutoPointer( CFUUIDCreate( nullptr ) );
        n3 = CF::AutoPointer( nullptr );
        
        ASSERT_TRUE(  n1.IsValid() );
        ASSERT_FALSE( n2.IsValid() );
        ASSERT_FALSE( n3.IsValid() );
    }
}

TEST( CFPP_Number, OperatorAssignCFType )
{
    CF::Number n;
    
    ASSERT_TRUE( n == 0 );
    
    n = static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() );
    
    ASSERT_TRUE( n == 1 );
    
    n = static_cast< CFTypeRef >( nullptr );
    
    ASSERT_FALSE( n.IsValid() );
    ASSERT_TRUE( n == 0 );
    
    n = static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() );
    
    ASSERT_TRUE( n.IsValid() );
    ASSERT_TRUE( n == 1 );
}

TEST( CFPP_Number, OperatorAssignCFNumber )
{
    CF::Number n;
    
    ASSERT_TRUE( n == 0 );
    
    n = static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() );
    
    ASSERT_TRUE( n == 1 );
    
    n = static_cast< CFNumberRef >( nullptr );
    
    ASSERT_FALSE( n.IsValid() );
    ASSERT_TRUE( n == 0 );
    
    n = static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() );
    
    ASSERT_TRUE( n.IsValid() );
    ASSERT_TRUE( n == 1 );
}

TEST( CFPP_Number, OperatorAssignNullPointer )
{
    CF::Number n;
    
    ASSERT_TRUE( n.IsValid() );
    
    n = nullptr;
    
    ASSERT_FALSE( n.IsValid() );
}

template< typename T >
void TMPL_CFPP_Number_OperatorAssign_T()
{
    CF::Number n;
    
    ASSERT_TRUE( n == 0 );
    
    n = static_cast< T >( 1 );
    
    ASSERT_TRUE( n == 1 );
}

TEST( CFPP_Number, OperatorAssign_T )
{
    TMPL_CFPP_Number_OperatorAssign_T< SInt8 >();
    TMPL_CFPP_Number_OperatorAssign_T< SInt16 >();
    TMPL_CFPP_Number_OperatorAssign_T< SInt32 >();
    TMPL_CFPP_Number_OperatorAssign_T< SInt64 >();
    TMPL_CFPP_Number_OperatorAssign_T< SInt8 >();
    TMPL_CFPP_Number_OperatorAssign_T< SInt16 >();
    TMPL_CFPP_Number_OperatorAssign_T< SInt32 >();
    TMPL_CFPP_Number_OperatorAssign_T< SInt64 >();
    TMPL_CFPP_Number_OperatorAssign_T< Float32 >();
    TMPL_CFPP_Number_OperatorAssign_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorAssign_T< signed char >();
    TMPL_CFPP_Number_OperatorAssign_T< signed short >();
    TMPL_CFPP_Number_OperatorAssign_T< signed int >();
    TMPL_CFPP_Number_OperatorAssign_T< signed long >();
    TMPL_CFPP_Number_OperatorAssign_T< signed long long >();
    TMPL_CFPP_Number_OperatorAssign_T< unsigned char >();
    TMPL_CFPP_Number_OperatorAssign_T< unsigned short >();
    TMPL_CFPP_Number_OperatorAssign_T< unsigned int >();
    TMPL_CFPP_Number_OperatorAssign_T< unsigned long >();
    TMPL_CFPP_Number_OperatorAssign_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorAssign_T< float >();
    TMPL_CFPP_Number_OperatorAssign_T< double >();
}

TEST( CFPP_Number, OperatorEqualNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 == CF::Number(  1 ) );
        ASSERT_FALSE( n2 == CF::Number( 43 ) );
        ASSERT_FALSE( n3 == CF::Number(  1 ) );
        
        ASSERT_TRUE( n1 == CF::Number(  0 ) );
        ASSERT_TRUE( n2 == CF::Number( 42 ) );
        ASSERT_TRUE( n3 == CF::Number(  0 ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE(  n1 == n3 );
        ASSERT_FALSE( n2 == n3 );
        ASSERT_TRUE(  n3 == n3 );
    }
}

TEST( CFPP_Number, OperatorEqualCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 == static_cast< CFTypeRef >( CF::Number(  1 ).GetCFObject() ) );
        ASSERT_FALSE( n2 == static_cast< CFTypeRef >( CF::Number( 43 ).GetCFObject() ) );
        ASSERT_FALSE( n3 == static_cast< CFTypeRef >( CF::Number(  1 ).GetCFObject() ) );
        
        ASSERT_TRUE( n1 == static_cast< CFTypeRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_TRUE( n2 == static_cast< CFTypeRef >( CF::Number( 42 ).GetCFObject() ) );
        ASSERT_TRUE( n3 == static_cast< CFTypeRef >( CF::Number(  0 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE(  n1 == static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n2 == static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_TRUE(  n3 == static_cast< CFTypeRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE(  n1 == static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n2 == static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE(  n3 == static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
    }
}

TEST( CFPP_Number, OperatorEqualCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 == static_cast< CFNumberRef >( CF::Number(  1 ).GetCFObject() ) );
        ASSERT_FALSE( n2 == static_cast< CFNumberRef >( CF::Number( 43 ).GetCFObject() ) );
        ASSERT_FALSE( n3 == static_cast< CFNumberRef >( CF::Number(  1 ).GetCFObject() ) );
        
        ASSERT_TRUE( n1 == static_cast< CFNumberRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_TRUE( n2 == static_cast< CFNumberRef >( CF::Number( 42 ).GetCFObject() ) );
        ASSERT_TRUE( n3 == static_cast< CFNumberRef >( CF::Number(  0 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE(  n1 == static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n2 == static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_TRUE(  n3 == static_cast< CFNumberRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE(  n1 == static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n2 == static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE(  n3 == static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_FALSE( n3 == static_cast< T >(  1 ) );
    ASSERT_FALSE( n2 == static_cast< T >( 43 ) );
    ASSERT_FALSE( n1 == static_cast< T >(  1 ) );
    
    ASSERT_TRUE( n1 == static_cast< T >(  0 ) );
    ASSERT_TRUE( n2 == static_cast< T >( 42 ) );
    ASSERT_TRUE( n3 == static_cast< T >(  0 ) );
}

TEST( CFPP_Number, OperatorEqual_T )
{
    TMPL_CFPP_Number_OperatorEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorEqual_T< UInt64 >();
    TMPL_CFPP_Number_OperatorEqual_T< Float32 >();
    TMPL_CFPP_Number_OperatorEqual_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorEqual_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorEqual_T< float >();
    TMPL_CFPP_Number_OperatorEqual_T< double >();
}

TEST( CFPP_Number, OperatorNotEqualNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 != CF::Number(  1 ) );
        ASSERT_TRUE( n2 != CF::Number( 43 ) );
        ASSERT_TRUE( n3 != CF::Number(  1 ) );
        
        ASSERT_FALSE( n1 != CF::Number(  0 ) );
        ASSERT_FALSE( n2 != CF::Number( 42 ) );
        ASSERT_FALSE( n3 != CF::Number(  0 ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 != n3 );
        ASSERT_TRUE(  n2 != n3 );
        ASSERT_FALSE( n3 != n3 );
    }
}

TEST( CFPP_Number, OperatorNotEqualCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 != static_cast< CFTypeRef >( CF::Number(  1 ).GetCFObject() ) );
        ASSERT_TRUE( n2 != static_cast< CFTypeRef >( CF::Number( 43 ).GetCFObject() ) );
        ASSERT_TRUE( n3 != static_cast< CFTypeRef >( CF::Number(  1 ).GetCFObject() ) );
        
        ASSERT_FALSE( n1 != static_cast< CFTypeRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_FALSE( n2 != static_cast< CFTypeRef >( CF::Number( 42 ).GetCFObject() ) );
        ASSERT_FALSE( n3 != static_cast< CFTypeRef >( CF::Number(  0 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 != static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_TRUE(  n2 != static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n3 != static_cast< CFTypeRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 != static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE(  n2 != static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n3 != static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
    }
}

TEST( CFPP_Number, OperatorNotEqualCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 != static_cast< CFNumberRef >( CF::Number(  1 ).GetCFObject() ) );
        ASSERT_TRUE( n2 != static_cast< CFNumberRef >( CF::Number( 43 ).GetCFObject() ) );
        ASSERT_TRUE( n3 != static_cast< CFNumberRef >( CF::Number(  1 ).GetCFObject() ) );
        
        ASSERT_FALSE( n1 != static_cast< CFNumberRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_FALSE( n2 != static_cast< CFNumberRef >( CF::Number( 42 ).GetCFObject() ) );
        ASSERT_FALSE( n3 != static_cast< CFNumberRef >( CF::Number(  0 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 != static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_TRUE(  n2 != static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n3 != static_cast< CFNumberRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 != static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE(  n2 != static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n3 != static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorNotEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_TRUE( n3 != static_cast< T >(  1 ) );
    ASSERT_TRUE( n2 != static_cast< T >( 43 ) );
    ASSERT_TRUE( n1 != static_cast< T >(  1 ) );
    
    ASSERT_FALSE( n1 != static_cast< T >(  0 ) );
    ASSERT_FALSE( n2 != static_cast< T >( 42 ) );
    ASSERT_FALSE( n3 != static_cast< T >(  0 ) );
}

TEST( CFPP_Number, OperatorNotEqual_T )
{
    TMPL_CFPP_Number_OperatorNotEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorNotEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorNotEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorNotEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorNotEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorNotEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorNotEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorNotEqual_T< UInt64 >();
    TMPL_CFPP_Number_OperatorNotEqual_T< Float32 >();
    TMPL_CFPP_Number_OperatorNotEqual_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorNotEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorNotEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorNotEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorNotEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorNotEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorNotEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorNotEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorNotEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorNotEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorNotEqual_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorNotEqual_T< float >();
    TMPL_CFPP_Number_OperatorNotEqual_T< double >();
}

TEST( CFPP_Number, OperatorGreaterOrEqualNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 >= CF::Number(  0 ) );
        ASSERT_TRUE( n1 >= CF::Number( -1 ) );
        ASSERT_TRUE( n2 >= CF::Number( 42 ) );
        ASSERT_TRUE( n2 >= CF::Number( 41 ) );
        ASSERT_TRUE( n3 >= CF::Number(  0 ) );
        ASSERT_TRUE( n3 >= CF::Number( -1 ) );
        
        ASSERT_FALSE( n1 >= CF::Number( 100 ) );
        ASSERT_FALSE( n2 >= CF::Number( 100 ) );
        ASSERT_FALSE( n3 >= CF::Number( 100 ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 >= n3 );
        ASSERT_TRUE( n2 >= n3 );
        ASSERT_TRUE( n3 >= n3 );
    }
}

TEST( CFPP_Number, OperatorGreaterOrEqualCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 >= static_cast< CFTypeRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_TRUE( n1 >= static_cast< CFTypeRef >( CF::Number( -1 ).GetCFObject() ) );
        ASSERT_TRUE( n2 >= static_cast< CFTypeRef >( CF::Number( 42 ).GetCFObject() ) );
        ASSERT_TRUE( n2 >= static_cast< CFTypeRef >( CF::Number( 41 ).GetCFObject() ) );
        ASSERT_TRUE( n3 >= static_cast< CFTypeRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_TRUE( n3 >= static_cast< CFTypeRef >( CF::Number( -1 ).GetCFObject() ) );
        
        ASSERT_FALSE( n1 >= static_cast< CFTypeRef >( CF::Number( 100 ).GetCFObject() ) );
        ASSERT_FALSE( n2 >= static_cast< CFTypeRef >( CF::Number( 100 ).GetCFObject() ) );
        ASSERT_FALSE( n3 >= static_cast< CFTypeRef >( CF::Number( 100 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 >= static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_TRUE( n2 >= static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_TRUE( n3 >= static_cast< CFTypeRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 >= static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE( n2 >= static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE( n3 >= static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
    }
}

TEST( CFPP_Number, OperatorGreaterOrEqualCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 >= static_cast< CFNumberRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_TRUE( n1 >= static_cast< CFNumberRef >( CF::Number( -1 ).GetCFObject() ) );
        ASSERT_TRUE( n2 >= static_cast< CFNumberRef >( CF::Number( 42 ).GetCFObject() ) );
        ASSERT_TRUE( n2 >= static_cast< CFNumberRef >( CF::Number( 41 ).GetCFObject() ) );
        ASSERT_TRUE( n3 >= static_cast< CFNumberRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_TRUE( n3 >= static_cast< CFNumberRef >( CF::Number( -1 ).GetCFObject() ) );
        
        ASSERT_FALSE( n1 >= static_cast< CFNumberRef >( CF::Number( 100 ).GetCFObject() ) );
        ASSERT_FALSE( n2 >= static_cast< CFNumberRef >( CF::Number( 100 ).GetCFObject() ) );
        ASSERT_FALSE( n3 >= static_cast< CFNumberRef >( CF::Number( 100 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 >= static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_TRUE( n2 >= static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_TRUE( n3 >= static_cast< CFNumberRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 >= static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE( n2 >= static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE( n3 >= static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorGreaterOrEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_TRUE( n1 >= static_cast< T >(  0 ) );
    ASSERT_TRUE( n1 >= static_cast< T >( -1 ) );
    ASSERT_TRUE( n2 >= static_cast< T >( 42 ) );
    ASSERT_TRUE( n2 >= static_cast< T >( 41 ) );
    ASSERT_TRUE( n3 >= static_cast< T >(  0 ) );
    ASSERT_TRUE( n3 >= static_cast< T >( -1 ) );
    
    ASSERT_FALSE( n1 >= static_cast< T >( 100 ) );
    ASSERT_FALSE( n2 >= static_cast< T >( 100 ) );
    ASSERT_FALSE( n3 >= static_cast< T >( 100 ) );
}

TEST( CFPP_Number, OperatorGreaterOrEqual_T )
{
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< UInt64 >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< Float32 >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< float >();
    TMPL_CFPP_Number_OperatorGreaterOrEqual_T< double >();
}

TEST( CFPP_Number, OperatorLesserOrEqualNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 <= CF::Number(  0 ) );
        ASSERT_TRUE( n1 <= CF::Number(  1 ) );
        ASSERT_TRUE( n2 <= CF::Number( 42 ) );
        ASSERT_TRUE( n2 <= CF::Number( 43 ) );
        ASSERT_TRUE( n3 <= CF::Number(  0 ) );
        ASSERT_TRUE( n3 <= CF::Number(  1 ) );
        
        ASSERT_FALSE( n1 <= CF::Number( -100 ) );
        ASSERT_FALSE( n2 <= CF::Number( -100 ) );
        ASSERT_FALSE( n3 <= CF::Number( -100 ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE(  n1 <= n3 );
        ASSERT_FALSE( n2 <= n3 );
        ASSERT_TRUE(  n3 <= n3 );
    }
}

TEST( CFPP_Number, OperatorLesserOrEqualCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 <= static_cast< CFTypeRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_TRUE( n1 <= static_cast< CFTypeRef >( CF::Number(  1 ).GetCFObject() ) );
        ASSERT_TRUE( n2 <= static_cast< CFTypeRef >( CF::Number( 42 ).GetCFObject() ) );
        ASSERT_TRUE( n2 <= static_cast< CFTypeRef >( CF::Number( 43 ).GetCFObject() ) );
        ASSERT_TRUE( n3 <= static_cast< CFTypeRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_TRUE( n3 <= static_cast< CFTypeRef >( CF::Number(  1 ).GetCFObject() ) );
        
        ASSERT_FALSE( n1 <= static_cast< CFTypeRef >( CF::Number( -100 ).GetCFObject() ) );
        ASSERT_FALSE( n2 <= static_cast< CFTypeRef >( CF::Number( -100 ).GetCFObject() ) );
        ASSERT_FALSE( n3 <= static_cast< CFTypeRef >( CF::Number( -100 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE(  n1 <= static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n2 <= static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_TRUE(  n3 <= static_cast< CFTypeRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE(  n1 <= static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n2 <= static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE(  n3 <= static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
    }
}

TEST( CFPP_Number, OperatorLesserOrEqualCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE( n1 <= static_cast< CFNumberRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_TRUE( n1 <= static_cast< CFNumberRef >( CF::Number(  1 ).GetCFObject() ) );
        ASSERT_TRUE( n2 <= static_cast< CFNumberRef >( CF::Number( 42 ).GetCFObject() ) );
        ASSERT_TRUE( n2 <= static_cast< CFNumberRef >( CF::Number( 43 ).GetCFObject() ) );
        ASSERT_TRUE( n3 <= static_cast< CFNumberRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_TRUE( n3 <= static_cast< CFNumberRef >( CF::Number(  1 ).GetCFObject() ) );
        
        ASSERT_FALSE( n1 <= static_cast< CFNumberRef >( CF::Number( -100 ).GetCFObject() ) );
        ASSERT_FALSE( n2 <= static_cast< CFNumberRef >( CF::Number( -100 ).GetCFObject() ) );
        ASSERT_FALSE( n3 <= static_cast< CFNumberRef >( CF::Number( -100 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE(  n1 <= static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n2 <= static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_TRUE(  n3 <= static_cast< CFNumberRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_TRUE(  n1 <= static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n2 <= static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE(  n3 <= static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorLesserOrEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_TRUE( n1 <= static_cast< T >(  0 ) );
    ASSERT_TRUE( n1 <= static_cast< T >(  1 ) );
    ASSERT_TRUE( n2 <= static_cast< T >( 42 ) );
    ASSERT_TRUE( n2 <= static_cast< T >( 43 ) );
    ASSERT_TRUE( n3 <= static_cast< T >(  0 ) );
    ASSERT_TRUE( n3 <= static_cast< T >(  1 ) );
    
    ASSERT_FALSE( n1 <= static_cast< T >( -100 ) );
    ASSERT_FALSE( n2 <= static_cast< T >( -100 ) );
    ASSERT_FALSE( n3 <= static_cast< T >( -100 ) );
}

TEST( CFPP_Number, OperatorLesserOrEqual_T )
{
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< UInt64 >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< Float32 >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< float >();
    TMPL_CFPP_Number_OperatorLesserOrEqual_T< double >();
}

TEST( CFPP_Number, OperatorGreaterNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 > CF::Number( 100 ) );
        ASSERT_FALSE( n2 > CF::Number( 100 ) );
        ASSERT_FALSE( n2 > CF::Number(  42 ) );
        ASSERT_FALSE( n3 > CF::Number( 100 ) );
        
        ASSERT_TRUE( n1 > CF::Number( -100 ) );
        ASSERT_TRUE( n2 > CF::Number( -100 ) );
        ASSERT_TRUE( n3 > CF::Number( -100 ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 > n3 );
        ASSERT_TRUE(  n2 > n3 );
        ASSERT_FALSE( n3 > n3 );
    }
}

TEST( CFPP_Number, OperatorGreaterCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 > static_cast< CFTypeRef >( CF::Number( 100 ).GetCFObject() ) );
        ASSERT_FALSE( n2 > static_cast< CFTypeRef >( CF::Number( 100 ).GetCFObject() ) );
        ASSERT_FALSE( n2 > static_cast< CFTypeRef >( CF::Number(  42 ).GetCFObject() ) );
        ASSERT_FALSE( n3 > static_cast< CFTypeRef >( CF::Number( 100 ).GetCFObject() ) );
        
        ASSERT_TRUE( n1 > static_cast< CFTypeRef >( CF::Number( -100 ).GetCFObject() ) );
        ASSERT_TRUE( n2 > static_cast< CFTypeRef >( CF::Number( -100 ).GetCFObject() ) );
        ASSERT_TRUE( n3 > static_cast< CFTypeRef >( CF::Number( -100 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 > static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_TRUE(  n2 > static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n3 > static_cast< CFTypeRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 > static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE(  n2 > static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n3 > static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
    }
}

TEST( CFPP_Number, OperatorGreaterCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 > static_cast< CFNumberRef >( CF::Number( 100 ).GetCFObject() ) );
        ASSERT_FALSE( n2 > static_cast< CFNumberRef >( CF::Number( 100 ).GetCFObject() ) );
        ASSERT_FALSE( n2 > static_cast< CFNumberRef >( CF::Number(  42 ).GetCFObject() ) );
        ASSERT_FALSE( n3 > static_cast< CFNumberRef >( CF::Number( 100 ).GetCFObject() ) );
        
        ASSERT_TRUE( n1 > static_cast< CFNumberRef >( CF::Number( -100 ).GetCFObject() ) );
        ASSERT_TRUE( n2 > static_cast< CFNumberRef >( CF::Number( -100 ).GetCFObject() ) );
        ASSERT_TRUE( n3 > static_cast< CFNumberRef >( CF::Number( -100 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 > static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_TRUE(  n2 > static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n3 > static_cast< CFNumberRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 > static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE(  n2 > static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n3 > static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorGreater_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_FALSE( n1 > static_cast< T >( 100 ) );
    ASSERT_FALSE( n2 > static_cast< T >( 100 ) );
    ASSERT_FALSE( n2 > static_cast< T >(  42 ) );
    ASSERT_FALSE( n3 > static_cast< T >( 100 ) );
    
    ASSERT_TRUE( n1 > static_cast< T >( -100 ) );
    ASSERT_TRUE( n2 > static_cast< T >( -100 ) );
    ASSERT_TRUE( n3 > static_cast< T >( -100 ) );
}

TEST( CFPP_Number, OperatorGreater_T )
{
    TMPL_CFPP_Number_OperatorGreater_T< SInt8 >();
    TMPL_CFPP_Number_OperatorGreater_T< SInt16 >();
    TMPL_CFPP_Number_OperatorGreater_T< SInt32 >();
    TMPL_CFPP_Number_OperatorGreater_T< SInt64 >();
    TMPL_CFPP_Number_OperatorGreater_T< UInt8 >();
    TMPL_CFPP_Number_OperatorGreater_T< UInt16 >();
    TMPL_CFPP_Number_OperatorGreater_T< UInt32 >();
    TMPL_CFPP_Number_OperatorGreater_T< UInt64 >();
    TMPL_CFPP_Number_OperatorGreater_T< Float32 >();
    TMPL_CFPP_Number_OperatorGreater_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorGreater_T< signed char >();
    TMPL_CFPP_Number_OperatorGreater_T< signed short >();
    TMPL_CFPP_Number_OperatorGreater_T< signed int >();
    TMPL_CFPP_Number_OperatorGreater_T< signed long >();
    TMPL_CFPP_Number_OperatorGreater_T< signed long long >();
    TMPL_CFPP_Number_OperatorGreater_T< unsigned char >();
    TMPL_CFPP_Number_OperatorGreater_T< unsigned short >();
    TMPL_CFPP_Number_OperatorGreater_T< unsigned int >();
    TMPL_CFPP_Number_OperatorGreater_T< unsigned long >();
    TMPL_CFPP_Number_OperatorGreater_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorGreater_T< float >();
    TMPL_CFPP_Number_OperatorGreater_T< double >();
}

TEST( CFPP_Number, OperatorLesserNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 < CF::Number(  0 ) );
        ASSERT_FALSE( n2 < CF::Number(  0 ) );
        ASSERT_FALSE( n2 < CF::Number( 42 ) );
        ASSERT_FALSE( n3 < CF::Number(  0 ) );
        
        ASSERT_TRUE( n1 < CF::Number( 100 ) );
        ASSERT_TRUE( n2 < CF::Number( 100 ) );
        ASSERT_TRUE( n3 < CF::Number( 100 ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 < n3 );
        ASSERT_FALSE( n2 < n3 );
        ASSERT_FALSE( n3 < n3 );
    }
}

TEST( CFPP_Number, OperatorLesserCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 < static_cast< CFTypeRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_FALSE( n2 < static_cast< CFTypeRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_FALSE( n2 < static_cast< CFTypeRef >( CF::Number( 42 ).GetCFObject() ) );
        ASSERT_FALSE( n3 < static_cast< CFTypeRef >( CF::Number(  0 ).GetCFObject() ) );
        
        ASSERT_TRUE( n1 < static_cast< CFTypeRef >( CF::Number( 100 ).GetCFObject() ) );
        ASSERT_TRUE( n2 < static_cast< CFTypeRef >( CF::Number( 100 ).GetCFObject() ) );
        ASSERT_TRUE( n3 < static_cast< CFTypeRef >( CF::Number( 100 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 < static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n2 < static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n3 < static_cast< CFTypeRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 < static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n2 < static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n3 < static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
    }
}

TEST( CFPP_Number, OperatorLesserCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 < static_cast< CFNumberRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_FALSE( n2 < static_cast< CFNumberRef >( CF::Number(  0 ).GetCFObject() ) );
        ASSERT_FALSE( n2 < static_cast< CFNumberRef >( CF::Number( 42 ).GetCFObject() ) );
        ASSERT_FALSE( n3 < static_cast< CFNumberRef >( CF::Number(  0 ).GetCFObject() ) );
        
        ASSERT_TRUE( n1 < static_cast< CFNumberRef >( CF::Number( 100 ).GetCFObject() ) );
        ASSERT_TRUE( n2 < static_cast< CFNumberRef >( CF::Number( 100 ).GetCFObject() ) );
        ASSERT_TRUE( n3 < static_cast< CFNumberRef >( CF::Number( 100 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 < static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n2 < static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n3 < static_cast< CFNumberRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 < static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n2 < static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n3 < static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorLesser_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_FALSE( n1 < static_cast< T >(  0 ) );
    ASSERT_FALSE( n2 < static_cast< T >(  0 ) );
    ASSERT_FALSE( n2 < static_cast< T >( 42 ) );
    ASSERT_FALSE( n3 < static_cast< T >(  0 ) );
    
    ASSERT_TRUE( n1 < static_cast< T >( 100 ) );
    ASSERT_TRUE( n2 < static_cast< T >( 100 ) );
    ASSERT_TRUE( n3 < static_cast< T >( 100 ) );
}

TEST( CFPP_Number, OperatorLesser_T )
{
    TMPL_CFPP_Number_OperatorLesser_T< SInt8 >();
    TMPL_CFPP_Number_OperatorLesser_T< SInt16 >();
    TMPL_CFPP_Number_OperatorLesser_T< SInt32 >();
    TMPL_CFPP_Number_OperatorLesser_T< SInt64 >();
    TMPL_CFPP_Number_OperatorLesser_T< UInt8 >();
    TMPL_CFPP_Number_OperatorLesser_T< UInt16 >();
    TMPL_CFPP_Number_OperatorLesser_T< UInt32 >();
    TMPL_CFPP_Number_OperatorLesser_T< UInt64 >();
    TMPL_CFPP_Number_OperatorLesser_T< Float32 >();
    TMPL_CFPP_Number_OperatorLesser_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorLesser_T< signed char >();
    TMPL_CFPP_Number_OperatorLesser_T< signed short >();
    TMPL_CFPP_Number_OperatorLesser_T< signed int >();
    TMPL_CFPP_Number_OperatorLesser_T< signed long >();
    TMPL_CFPP_Number_OperatorLesser_T< signed long long >();
    TMPL_CFPP_Number_OperatorLesser_T< unsigned char >();
    TMPL_CFPP_Number_OperatorLesser_T< unsigned short >();
    TMPL_CFPP_Number_OperatorLesser_T< unsigned int >();
    TMPL_CFPP_Number_OperatorLesser_T< unsigned long >();
    TMPL_CFPP_Number_OperatorLesser_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorLesser_T< float >();
    TMPL_CFPP_Number_OperatorLesser_T< double >();
}

TEST( CFPP_Number, OperatorAndNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 && CF::Number( 0 ) );
        ASSERT_FALSE( n2 && CF::Number( 0 ) );
        ASSERT_FALSE( n3 && CF::Number( 0 ) );
        
        ASSERT_FALSE( n1 && CF::Number( 1 ) );
        ASSERT_TRUE(  n2 && CF::Number( 1 ) );
        ASSERT_FALSE( n3 && CF::Number( 1 ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 && n3 );
        ASSERT_FALSE( n2 && n3 );
        ASSERT_FALSE( n3 && n3 );
    }
}

TEST( CFPP_Number, OperatorAndCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 && static_cast< CFTypeRef >( CF::Number( 0 ).GetCFObject() ) );
        ASSERT_FALSE( n2 && static_cast< CFTypeRef >( CF::Number( 0 ).GetCFObject() ) );
        ASSERT_FALSE( n3 && static_cast< CFTypeRef >( CF::Number( 0 ).GetCFObject() ) );
        
        ASSERT_FALSE( n1 && static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() ) );
        ASSERT_TRUE(  n2 && static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() ) );
        ASSERT_FALSE( n3 && static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 && static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n2 && static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n3 && static_cast< CFTypeRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 && static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n2 && static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n3 && static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
    }
}

TEST( CFPP_Number, OperatorAndCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 && static_cast< CFNumberRef >( CF::Number( 0 ).GetCFObject() ) );
        ASSERT_FALSE( n2 && static_cast< CFNumberRef >( CF::Number( 0 ).GetCFObject() ) );
        ASSERT_FALSE( n3 && static_cast< CFNumberRef >( CF::Number( 0 ).GetCFObject() ) );
        
        ASSERT_FALSE( n1 && static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() ) );
        ASSERT_TRUE(  n2 && static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() ) );
        ASSERT_FALSE( n3 && static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 && static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n2 && static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n3 && static_cast< CFNumberRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 && static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n2 && static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n3 && static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorAnd_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_FALSE( n1 && static_cast< T >( 0 ) );
    ASSERT_FALSE( n2 && static_cast< T >( 0 ) );
    ASSERT_FALSE( n3 && static_cast< T >( 0 ) );
    
    ASSERT_FALSE( n1 && static_cast< T >( 1 ) );
    ASSERT_TRUE(  n2 && static_cast< T >( 1 ) );
    ASSERT_FALSE( n3 && static_cast< T >( 1 ) );
}

TEST( CFPP_Number, OperatorAnd_T )
{
    TMPL_CFPP_Number_OperatorAnd_T< SInt8 >();
    TMPL_CFPP_Number_OperatorAnd_T< SInt16 >();
    TMPL_CFPP_Number_OperatorAnd_T< SInt32 >();
    TMPL_CFPP_Number_OperatorAnd_T< SInt64 >();
    TMPL_CFPP_Number_OperatorAnd_T< UInt8 >();
    TMPL_CFPP_Number_OperatorAnd_T< UInt16 >();
    TMPL_CFPP_Number_OperatorAnd_T< UInt32 >();
    TMPL_CFPP_Number_OperatorAnd_T< UInt64 >();
    TMPL_CFPP_Number_OperatorAnd_T< Float32 >();
    TMPL_CFPP_Number_OperatorAnd_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorAnd_T< signed char >();
    TMPL_CFPP_Number_OperatorAnd_T< signed short >();
    TMPL_CFPP_Number_OperatorAnd_T< signed int >();
    TMPL_CFPP_Number_OperatorAnd_T< signed long >();
    TMPL_CFPP_Number_OperatorAnd_T< signed long long >();
    TMPL_CFPP_Number_OperatorAnd_T< unsigned char >();
    TMPL_CFPP_Number_OperatorAnd_T< unsigned short >();
    TMPL_CFPP_Number_OperatorAnd_T< unsigned int >();
    TMPL_CFPP_Number_OperatorAnd_T< unsigned long >();
    TMPL_CFPP_Number_OperatorAnd_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorAnd_T< float >();
    TMPL_CFPP_Number_OperatorAnd_T< double >();
}

TEST( CFPP_Number, OperatorOrNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 || CF::Number( 0 ) );
        ASSERT_TRUE(  n2 || CF::Number( 0 ) );
        ASSERT_FALSE( n3 || CF::Number( 0 ) );
        
        ASSERT_TRUE( n1 || CF::Number( 1 ) );
        ASSERT_TRUE( n2 || CF::Number( 1 ) );
        ASSERT_TRUE( n3 || CF::Number( 1 ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 || n3 );
        ASSERT_TRUE(  n2 || n3 );
        ASSERT_FALSE( n3 || n3 );
    }
}

TEST( CFPP_Number, OperatorOrCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 || static_cast< CFTypeRef >( CF::Number( 0 ).GetCFObject() ) );
        ASSERT_TRUE(  n2 || static_cast< CFTypeRef >( CF::Number( 0 ).GetCFObject() ) );
        ASSERT_FALSE( n3 || static_cast< CFTypeRef >( CF::Number( 0 ).GetCFObject() ) );
        
        ASSERT_TRUE( n1 || static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() ) );
        ASSERT_TRUE( n2 || static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() ) );
        ASSERT_TRUE( n3 || static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 || static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_TRUE(  n2 || static_cast< CFTypeRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n3 || static_cast< CFTypeRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 || static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE(  n2 || static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n3 || static_cast< CFTypeRef >( CF::Array().GetCFObject() ) );
    }
}

TEST( CFPP_Number, OperatorOrCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 || static_cast< CFNumberRef >( CF::Number( 0 ).GetCFObject() ) );
        ASSERT_TRUE(  n2 || static_cast< CFNumberRef >( CF::Number( 0 ).GetCFObject() ) );
        ASSERT_FALSE( n3 || static_cast< CFNumberRef >( CF::Number( 0 ).GetCFObject() ) );
        
        ASSERT_TRUE( n1 || static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() ) );
        ASSERT_TRUE( n2 || static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() ) );
        ASSERT_TRUE( n3 || static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 || static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_TRUE(  n2 || static_cast< CFNumberRef >( n3.GetCFObject() ) );
        ASSERT_FALSE( n3 || static_cast< CFNumberRef >( n3.GetCFObject() ) );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        ASSERT_FALSE( n1 || static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_TRUE(  n2 || static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
        ASSERT_FALSE( n3 || static_cast< CFNumberRef >( CF::Array().GetCFObject() ) );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorOr_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_FALSE( n1 || static_cast< T >( 0 ) );
    ASSERT_TRUE(  n2 || static_cast< T >( 0 ) );
    ASSERT_FALSE( n3 || static_cast< T >( 0 ) );
    
    ASSERT_TRUE( n1 || static_cast< T >( 1 ) );
    ASSERT_TRUE( n2 || static_cast< T >( 1 ) );
    ASSERT_TRUE( n3 || static_cast< T >( 1 ) );
}

TEST( CFPP_Number, OperatorOr_T )
{
    TMPL_CFPP_Number_OperatorOr_T< SInt8 >();
    TMPL_CFPP_Number_OperatorOr_T< SInt16 >();
    TMPL_CFPP_Number_OperatorOr_T< SInt32 >();
    TMPL_CFPP_Number_OperatorOr_T< SInt64 >();
    TMPL_CFPP_Number_OperatorOr_T< UInt8 >();
    TMPL_CFPP_Number_OperatorOr_T< UInt16 >();
    TMPL_CFPP_Number_OperatorOr_T< UInt32 >();
    TMPL_CFPP_Number_OperatorOr_T< UInt64 >();
    TMPL_CFPP_Number_OperatorOr_T< Float32 >();
    TMPL_CFPP_Number_OperatorOr_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorOr_T< signed char >();
    TMPL_CFPP_Number_OperatorOr_T< signed short >();
    TMPL_CFPP_Number_OperatorOr_T< signed int >();
    TMPL_CFPP_Number_OperatorOr_T< signed long >();
    TMPL_CFPP_Number_OperatorOr_T< signed long long >();
    TMPL_CFPP_Number_OperatorOr_T< unsigned char >();
    TMPL_CFPP_Number_OperatorOr_T< unsigned short >();
    TMPL_CFPP_Number_OperatorOr_T< unsigned int >();
    TMPL_CFPP_Number_OperatorOr_T< unsigned long >();
    TMPL_CFPP_Number_OperatorOr_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorOr_T< float >();
    TMPL_CFPP_Number_OperatorOr_T< double >();
}

TEST( CFPP_Number, OperatorBitwiseNot )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( ~n1,  -1 );
    ASSERT_EQ( ~n2, -43 );
    ASSERT_EQ( ~n3,  -1 );
}

TEST( CFPP_Number, OperatorLogicalNot )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( !n1, 1 );
    ASSERT_EQ( !n2, 0 );
    ASSERT_EQ( !n3, 1 );
}

TEST( CFPP_Number, OperatorPrefixIncrement )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    CF::Number n4( 42.0 );
    
    ASSERT_EQ( ++n1,  1 );
    ASSERT_EQ( ++n2, 43 );
    ASSERT_EQ( ++n3,  1 );
    ASSERT_EQ( ++n4, 43 );
    
    ASSERT_EQ( n1,  1 );
    ASSERT_EQ( n2, 43 );
    ASSERT_EQ( n3,  1 );
    ASSERT_EQ( n4, 43 );
}

TEST( CFPP_Number, OperatorPosfixIncrement )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    CF::Number n4( 42.0 );
    
    ASSERT_EQ( n1++,  0 );
    ASSERT_EQ( n2++, 42 );
    ASSERT_EQ( n3++,  0 );
    ASSERT_EQ( n4++, 42 );
    
    ASSERT_EQ( n1,  1 );
    ASSERT_EQ( n2, 43 );
    ASSERT_EQ( n3,  1 );
    ASSERT_EQ( n4, 43 );
}

TEST( CFPP_Number, OperatorPrefixDecrement )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    CF::Number n4( 42.0 );
    
    ASSERT_EQ( --n1, -1 );
    ASSERT_EQ( --n2, 41 );
    ASSERT_EQ( --n3, -1 );
    ASSERT_EQ( --n4, 41 );
    
    ASSERT_EQ( n1, -1 );
    ASSERT_EQ( n2, 41 );
    ASSERT_EQ( n3, -1 );
    ASSERT_EQ( n4, 41 );
}

TEST( CFPP_Number, OperatorPostfixDecrement )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    CF::Number n4( 42.0 );
    
    ASSERT_EQ( n1--,  0 );
    ASSERT_EQ( n2--, 42 );
    ASSERT_EQ( n3--,  0 );
    ASSERT_EQ( n4--, 42 );
    
    ASSERT_EQ( n1, -1 );
    ASSERT_EQ( n2, 41 );
    ASSERT_EQ( n3, -1 );
    ASSERT_EQ( n4, 41 );
}

TEST( CFPP_Number, OperatorPlusEqualNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 += CF::Number( 10 );
        n2 += CF::Number( 10 );
        n3 += CF::Number( 10 );
        
        ASSERT_EQ( n1, 10 );
        ASSERT_EQ( n2, 52 );
        ASSERT_EQ( n3, 10 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 += n3;
        n2 += n3;
        n3 += n3;
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

TEST( CFPP_Number, OperatorPlusEqualCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 += static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
        n2 += static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
        n3 += static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
        
        ASSERT_EQ( n1, 10 );
        ASSERT_EQ( n2, 52 );
        ASSERT_EQ( n3, 10 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 += static_cast< CFTypeRef >( n3.GetCFObject() );
        n2 += static_cast< CFTypeRef >( n3.GetCFObject() );
        n3 += static_cast< CFTypeRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 += static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n2 += static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n3 += static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

TEST( CFPP_Number, OperatorPlusEqualCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 += static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
        n2 += static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
        n3 += static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
        
        ASSERT_EQ( n1, 10 );
        ASSERT_EQ( n2, 52 );
        ASSERT_EQ( n3, 10 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 += static_cast< CFNumberRef >( n3.GetCFObject() );
        n2 += static_cast< CFNumberRef >( n3.GetCFObject() );
        n3 += static_cast< CFNumberRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 += static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n2 += static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n3 += static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorPlusEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 += static_cast< T >( 10 );
    n2 += static_cast< T >( 10 );
    n3 += static_cast< T >( 10 );
    
    ASSERT_EQ( n1, 10 );
    ASSERT_EQ( n2, 52 );
    ASSERT_EQ( n3, 10 );
}

TEST( CFPP_Number, OperatorPlusEqual_T )
{
    TMPL_CFPP_Number_OperatorPlusEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< UInt64 >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< Float32 >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorPlusEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< float >();
    TMPL_CFPP_Number_OperatorPlusEqual_T< double >();
}

TEST( CFPP_Number, OperatorMinusEqualNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 -= CF::Number( 10 );
        n2 -= CF::Number( 10 );
        n3 -= CF::Number( 10 );
        
        ASSERT_EQ( n1, -10 );
        ASSERT_EQ( n2,  32 );
        ASSERT_EQ( n3, -10 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 -= n3;
        n2 -= n3;
        n3 -= n3;
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

TEST( CFPP_Number, OperatorMinusEqualCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 -= static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
        n2 -= static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
        n3 -= static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
        
        ASSERT_EQ( n1, -10 );
        ASSERT_EQ( n2,  32 );
        ASSERT_EQ( n3, -10 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 -= static_cast< CFTypeRef >( n3.GetCFObject() );
        n2 -= static_cast< CFTypeRef >( n3.GetCFObject() );
        n3 -= static_cast< CFTypeRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 -= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n2 -= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n3 -= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

TEST( CFPP_Number, OperatorMinusEqualCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 -= static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
        n2 -= static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
        n3 -= static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
        
        ASSERT_EQ( n1, -10 );
        ASSERT_EQ( n2,  32 );
        ASSERT_EQ( n3, -10 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 -= static_cast< CFNumberRef >( n3.GetCFObject() );
        n2 -= static_cast< CFNumberRef >( n3.GetCFObject() );
        n3 -= static_cast< CFNumberRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 -= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n2 -= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n3 -= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorMinusEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 -= static_cast< T >( 10 );
    n2 -= static_cast< T >( 10 );
    n3 -= static_cast< T >( 10 );
    
    ASSERT_EQ( n1, -10 );
    ASSERT_EQ( n2,  32 );
    ASSERT_EQ( n3, -10 );
}

TEST( CFPP_Number, OperatorMinusEqual_T )
{
    TMPL_CFPP_Number_OperatorMinusEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< UInt64 >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< Float32 >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorMinusEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< float >();
    TMPL_CFPP_Number_OperatorMinusEqual_T< double >();
}

TEST( CFPP_Number, OperatorMultiplyEqualNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 *= CF::Number( 10 );
        n2 *= CF::Number( 10 );
        n3 *= CF::Number( 10 );
        
        ASSERT_EQ( n1,   0 );
        ASSERT_EQ( n2, 420 );
        ASSERT_EQ( n3,   0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 *= n3;
        n2 *= n3;
        n3 *= n3;
        
        ASSERT_EQ( n1, 0 );
        ASSERT_EQ( n2, 0 );
        ASSERT_EQ( n3, 0 );
    }
}

TEST( CFPP_Number, OperatorMultiplyEqualCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 *= static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
        n2 *= static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
        n3 *= static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
        
        ASSERT_EQ( n1,   0 );
        ASSERT_EQ( n2, 420 );
        ASSERT_EQ( n3,   0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 *= static_cast< CFTypeRef >( n3.GetCFObject() );
        n2 *= static_cast< CFTypeRef >( n3.GetCFObject() );
        n3 *= static_cast< CFTypeRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1, 0 );
        ASSERT_EQ( n2, 0 );
        ASSERT_EQ( n3, 0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 *= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n2 *= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n3 *= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1, 0 );
        ASSERT_EQ( n2, 0 );
        ASSERT_EQ( n3, 0 );
    }
}

TEST( CFPP_Number, OperatorMultiplyEqualCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 *= static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
        n2 *= static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
        n3 *= static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
        
        ASSERT_EQ( n1,   0 );
        ASSERT_EQ( n2, 420 );
        ASSERT_EQ( n3,   0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 *= static_cast< CFNumberRef >( n3.GetCFObject() );
        n2 *= static_cast< CFNumberRef >( n3.GetCFObject() );
        n3 *= static_cast< CFNumberRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1, 0 );
        ASSERT_EQ( n2, 0 );
        ASSERT_EQ( n3, 0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 *= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n2 *= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n3 *= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1, 0 );
        ASSERT_EQ( n2, 0 );
        ASSERT_EQ( n3, 0 );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorMultiplyEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 *= static_cast< T >( 10 );
    n2 *= static_cast< T >( 10 );
    n3 *= static_cast< T >( 10 );
    
    ASSERT_EQ( n1,   0 );
    ASSERT_EQ( n2, 420 );
    ASSERT_EQ( n3,   0 );
}

TEST( CFPP_Number, OperatorMultiplyEqual_T )
{
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< UInt64 >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< Float32 >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< float >();
    TMPL_CFPP_Number_OperatorMultiplyEqual_T< double >();
}

TEST( CFPP_Number, OperatorDivideEqualNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 /= CF::Number( 10 );
    n2 /= CF::Number( 10 );
    n3 /= CF::Number( 10 );
    
    ASSERT_TRUE( FloatIsEqual( n1, 0.0 ) );
    ASSERT_TRUE( FloatIsEqual( n2, 4.2 ) );
    ASSERT_TRUE( FloatIsEqual( n3, 0.0 ) );
    
    ASSERT_THROW( n1 /= n3, std::runtime_error );
    ASSERT_THROW( n2 /= n3, std::runtime_error );
    ASSERT_THROW( n3 /= n3, std::runtime_error );
}

TEST( CFPP_Number, OperatorDivideEqualCFType )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 /= static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
    n2 /= static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
    n3 /= static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
    
    ASSERT_TRUE( FloatIsEqual( n1, 0.0 ) );
    ASSERT_TRUE( FloatIsEqual( n2, 4.2 ) );
    ASSERT_TRUE( FloatIsEqual( n3, 0.0 ) );
    
    ASSERT_THROW( n1 /= static_cast< CFTypeRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 /= static_cast< CFTypeRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 /= static_cast< CFTypeRef >( n3.GetCFObject() ), std::runtime_error );
    
    ASSERT_THROW( n1 /= static_cast< CFTypeRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 /= static_cast< CFTypeRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 /= static_cast< CFTypeRef >( CF::Array().GetCFObject() ), std::runtime_error );
}

TEST( CFPP_Number, OperatorDivideEqualCFNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 /= static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
    n2 /= static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
    n3 /= static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
    
    ASSERT_TRUE( FloatIsEqual( n1, 0.0 ) );
    ASSERT_TRUE( FloatIsEqual( n2, 4.2 ) );
    ASSERT_TRUE( FloatIsEqual( n3, 0.0 ) );
    
    ASSERT_THROW( n1 /= static_cast< CFNumberRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 /= static_cast< CFNumberRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 /= static_cast< CFNumberRef >( n3.GetCFObject() ), std::runtime_error );
    
    ASSERT_THROW( n1 /= static_cast< CFNumberRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 /= static_cast< CFNumberRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 /= static_cast< CFNumberRef >( CF::Array().GetCFObject() ), std::runtime_error );
}

template< typename T >
void TMPL_CFPP_Number_OperatorDivideEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 /= static_cast< T >( 10 );
    n2 /= static_cast< T >( 10 );
    n3 /= static_cast< T >( 10 );
    
    ASSERT_TRUE( FloatIsEqual( n1, 0.0 ) );
    ASSERT_TRUE( FloatIsEqual( n2, 4.2 ) );
    ASSERT_TRUE( FloatIsEqual( n3, 0.0 ) );
    
    ASSERT_THROW( n1 /= static_cast< T >( 0 ), std::runtime_error );
    ASSERT_THROW( n2 /= static_cast< T >( 0 ), std::runtime_error );
    ASSERT_THROW( n3 /= static_cast< T >( 0 ), std::runtime_error );
}

TEST( CFPP_Number, OperatorDivideEqual_T )
{
    TMPL_CFPP_Number_OperatorDivideEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< UInt64 >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< Float32 >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorDivideEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< float >();
    TMPL_CFPP_Number_OperatorDivideEqual_T< double >();
}

TEST( CFPP_Number, OperatorOrEqualNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 |= CF::Number( 21 );
        n2 |= CF::Number( 21 );
        n3 |= CF::Number( 21 );
        
        ASSERT_EQ( n1, 21 );
        ASSERT_EQ( n2, 63 );
        ASSERT_EQ( n3, 21 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 |= n3;
        n2 |= n3;
        n3 |= n3;
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

TEST( CFPP_Number, OperatorOrEqualCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 |= static_cast< CFTypeRef >( CF::Number( 21 ).GetCFObject() );
        n2 |= static_cast< CFTypeRef >( CF::Number( 21 ).GetCFObject() );
        n3 |= static_cast< CFTypeRef >( CF::Number( 21 ).GetCFObject() );
        
        ASSERT_EQ( n1, 21 );
        ASSERT_EQ( n2, 63 );
        ASSERT_EQ( n3, 21 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 |= static_cast< CFTypeRef >( n3.GetCFObject() );
        n2 |= static_cast< CFTypeRef >( n3.GetCFObject() );
        n3 |= static_cast< CFTypeRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 |= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n2 |= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n3 |= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

TEST( CFPP_Number, OperatorOrEqualCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 |= static_cast< CFNumberRef >( CF::Number( 21 ).GetCFObject() );
        n2 |= static_cast< CFNumberRef >( CF::Number( 21 ).GetCFObject() );
        n3 |= static_cast< CFNumberRef >( CF::Number( 21 ).GetCFObject() );
        
        ASSERT_EQ( n1, 21 );
        ASSERT_EQ( n2, 63 );
        ASSERT_EQ( n3, 21 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 |= static_cast< CFNumberRef >( n3.GetCFObject() );
        n2 |= static_cast< CFNumberRef >( n3.GetCFObject() );
        n3 |= static_cast< CFNumberRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 |= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n2 |= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n3 |= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorOrEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 |= static_cast< T >( 21 );
    n2 |= static_cast< T >( 21 );
    n3 |= static_cast< T >( 21 );
    
    ASSERT_EQ( n1, 21 );
    ASSERT_EQ( n2, 63 );
    ASSERT_EQ( n3, 21 );
}

TEST( CFPP_Number, OperatorOrEqual_T )
{
    TMPL_CFPP_Number_OperatorOrEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorOrEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorOrEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorOrEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorOrEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorOrEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorOrEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorOrEqual_T< UInt64 >();
    
    TMPL_CFPP_Number_OperatorOrEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorOrEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorOrEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorOrEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorOrEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorOrEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorOrEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorOrEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorOrEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorOrEqual_T< unsigned long long >();
}

TEST( CFPP_Number, OperatorAndEqualNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 &= CF::Number( 12 );
        n2 &= CF::Number( 12 );
        n3 &= CF::Number( 12 );
        
        ASSERT_EQ( n1, 0 );
        ASSERT_EQ( n2, 8 );
        ASSERT_EQ( n3, 0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 &= n3;
        n2 &= n3;
        n3 &= n3;
        
        ASSERT_EQ( n1, 0 );
        ASSERT_EQ( n2, 0 );
        ASSERT_EQ( n3, 0 );
    }
}

TEST( CFPP_Number, OperatorAndEqualCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 &= static_cast< CFTypeRef >( CF::Number( 12 ).GetCFObject() );
        n2 &= static_cast< CFTypeRef >( CF::Number( 12 ).GetCFObject() );
        n3 &= static_cast< CFTypeRef >( CF::Number( 12 ).GetCFObject() );
        
        ASSERT_EQ( n1, 0 );
        ASSERT_EQ( n2, 8 );
        ASSERT_EQ( n3, 0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 &= static_cast< CFTypeRef >( n3.GetCFObject() );
        n2 &= static_cast< CFTypeRef >( n3.GetCFObject() );
        n3 &= static_cast< CFTypeRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1, 0 );
        ASSERT_EQ( n2, 0 );
        ASSERT_EQ( n3, 0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 &= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n2 &= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n3 &= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1, 0 );
        ASSERT_EQ( n2, 0 );
        ASSERT_EQ( n3, 0 );
    }
}

TEST( CFPP_Number, OperatorAndEqualCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 &= static_cast< CFNumberRef >( CF::Number( 12 ).GetCFObject() );
        n2 &= static_cast< CFNumberRef >( CF::Number( 12 ).GetCFObject() );
        n3 &= static_cast< CFNumberRef >( CF::Number( 12 ).GetCFObject() );
        
        ASSERT_EQ( n1, 0 );
        ASSERT_EQ( n2, 8 );
        ASSERT_EQ( n3, 0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 &= static_cast< CFNumberRef >( n3.GetCFObject() );
        n2 &= static_cast< CFNumberRef >( n3.GetCFObject() );
        n3 &= static_cast< CFNumberRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1, 0 );
        ASSERT_EQ( n2, 0 );
        ASSERT_EQ( n3, 0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 &= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n2 &= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n3 &= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1, 0 );
        ASSERT_EQ( n2, 0 );
        ASSERT_EQ( n3, 0 );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorAndEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 &= static_cast< T >( 12 );
    n2 &= static_cast< T >( 12 );
    n3 &= static_cast< T >( 12 );
    
    ASSERT_EQ( n1, 0 );
    ASSERT_EQ( n2, 8 );
    ASSERT_EQ( n3, 0 );
}

TEST( CFPP_Number, OperatorAndEqual_T )
{
    TMPL_CFPP_Number_OperatorAndEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorAndEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorAndEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorAndEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorAndEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorAndEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorAndEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorAndEqual_T< UInt64 >();
    
    TMPL_CFPP_Number_OperatorAndEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorAndEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorAndEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorAndEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorAndEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorAndEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorAndEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorAndEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorAndEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorAndEqual_T< unsigned long long >();
}

TEST( CFPP_Number, OperatorModEqualNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 %= CF::Number( 10 );
    n2 %= CF::Number( 10 );
    n3 %= CF::Number( 10 );
    
    ASSERT_EQ( n1, 0 );
    ASSERT_EQ( n2, 2 );
    ASSERT_EQ( n3, 0 );
    
    ASSERT_THROW( n1 %= n3, std::runtime_error );
    ASSERT_THROW( n2 %= n3, std::runtime_error );
    ASSERT_THROW( n3 %= n3, std::runtime_error );
}

TEST( CFPP_Number, OperatorModEqualCFType )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 %= static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
    n2 %= static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
    n3 %= static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() );
    
    ASSERT_EQ( n1, 0 );
    ASSERT_EQ( n2, 2 );
    ASSERT_EQ( n3, 0 );
    
    ASSERT_THROW( n1 %= static_cast< CFTypeRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 %= static_cast< CFTypeRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 %= static_cast< CFTypeRef >( n3.GetCFObject() ), std::runtime_error );
    
    ASSERT_THROW( n1 %= static_cast< CFTypeRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 %= static_cast< CFTypeRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 %= static_cast< CFTypeRef >( CF::Array().GetCFObject() ), std::runtime_error );
}

TEST( CFPP_Number, OperatorModEqualCFNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 %= static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
    n2 %= static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
    n3 %= static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() );
    
    ASSERT_EQ( n1, 0 );
    ASSERT_EQ( n2, 2 );
    ASSERT_EQ( n3, 0 );
    
    ASSERT_THROW( n1 %= static_cast< CFNumberRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 %= static_cast< CFNumberRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 %= static_cast< CFNumberRef >( n3.GetCFObject() ), std::runtime_error );
    
    ASSERT_THROW( n1 %= static_cast< CFNumberRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 %= static_cast< CFNumberRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 %= static_cast< CFNumberRef >( CF::Array().GetCFObject() ), std::runtime_error );
}

template< typename T >
void TMPL_CFPP_Number_OperatorModEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 %= static_cast< T >( 10 );
    n2 %= static_cast< T >( 10 );
    n3 %= static_cast< T >( 10 );
    
    ASSERT_EQ( n1, 0 );
    ASSERT_EQ( n2, 2 );
    ASSERT_EQ( n3, 0 );
    
    ASSERT_THROW( n1 %= static_cast< T >( 0 ), std::runtime_error );
    ASSERT_THROW( n2 %= static_cast< T >( 0 ), std::runtime_error );
    ASSERT_THROW( n3 %= static_cast< T >( 0 ), std::runtime_error );
}

TEST( CFPP_Number, OperatorModEqual_T )
{
    TMPL_CFPP_Number_OperatorModEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorModEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorModEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorModEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorModEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorModEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorModEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorModEqual_T< UInt64 >();
    
    TMPL_CFPP_Number_OperatorModEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorModEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorModEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorModEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorModEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorModEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorModEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorModEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorModEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorModEqual_T< unsigned long long >();
}

TEST( CFPP_Number, OperatorXorEqualNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 ^= CF::Number( 43 );
        n2 ^= CF::Number( 43 );
        n3 ^= CF::Number( 43 );
        
        ASSERT_EQ( n1, 43 );
        ASSERT_EQ( n2,  1 );
        ASSERT_EQ( n3, 43 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 ^= n3;
        n2 ^= n3;
        n3 ^= n3;
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

TEST( CFPP_Number, OperatorXorEqualCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 ^= static_cast< CFTypeRef >( CF::Number( 43 ).GetCFObject() );
        n2 ^= static_cast< CFTypeRef >( CF::Number( 43 ).GetCFObject() );
        n3 ^= static_cast< CFTypeRef >( CF::Number( 43 ).GetCFObject() );
        
        ASSERT_EQ( n1, 43 );
        ASSERT_EQ( n2,  1 );
        ASSERT_EQ( n3, 43 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 ^= static_cast< CFTypeRef >( n3.GetCFObject() );
        n2 ^= static_cast< CFTypeRef >( n3.GetCFObject() );
        n3 ^= static_cast< CFTypeRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 ^= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n2 ^= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n3 ^= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

TEST( CFPP_Number, OperatorXorEqualCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 ^= static_cast< CFNumberRef >( CF::Number( 43 ).GetCFObject() );
        n2 ^= static_cast< CFNumberRef >( CF::Number( 43 ).GetCFObject() );
        n3 ^= static_cast< CFNumberRef >( CF::Number( 43 ).GetCFObject() );
        
        ASSERT_EQ( n1, 43 );
        ASSERT_EQ( n2,  1 );
        ASSERT_EQ( n3, 43 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 ^= static_cast< CFNumberRef >( n3.GetCFObject() );
        n2 ^= static_cast< CFNumberRef >( n3.GetCFObject() );
        n3 ^= static_cast< CFNumberRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 ^= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n2 ^= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n3 ^= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorXorEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 ^= static_cast< T >( 43 );
    n2 ^= static_cast< T >( 43 );
    n3 ^= static_cast< T >( 43 );
    
    ASSERT_EQ( n1, 43 );
    ASSERT_EQ( n2,  1 );
    ASSERT_EQ( n3, 43 );
}

TEST( CFPP_Number, OperatorXorEqual_T )
{
    TMPL_CFPP_Number_OperatorXorEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorXorEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorXorEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorXorEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorXorEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorXorEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorXorEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorXorEqual_T< UInt64 >();
    
    TMPL_CFPP_Number_OperatorXorEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorXorEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorXorEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorXorEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorXorEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorXorEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorXorEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorXorEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorXorEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorXorEqual_T< unsigned long long >();
}

TEST( CFPP_Number, OperatorLeftShiftEqualNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 <<= CF::Number( 1 );
        n2 <<= CF::Number( 1 );
        n3 <<= CF::Number( 1 );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 84 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 <<= n3;
        n2 <<= n3;
        n3 <<= n3;
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

TEST( CFPP_Number, OperatorLeftShiftEqualCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 <<= static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() );
        n2 <<= static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() );
        n3 <<= static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 84 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 <<= static_cast< CFTypeRef >( n3.GetCFObject() );
        n2 <<= static_cast< CFTypeRef >( n3.GetCFObject() );
        n3 <<= static_cast< CFTypeRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 <<= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n2 <<= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n3 <<= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

TEST( CFPP_Number, OperatorLeftShiftEqualCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 <<= static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() );
        n2 <<= static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() );
        n3 <<= static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 84 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 <<= static_cast< CFNumberRef >( n3.GetCFObject() );
        n2 <<= static_cast< CFNumberRef >( n3.GetCFObject() );
        n3 <<= static_cast< CFNumberRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 <<= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n2 <<= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n3 <<= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorLeftShiftEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 <<= static_cast< T >( 1 );
    n2 <<= static_cast< T >( 1 );
    n3 <<= static_cast< T >( 1 );
    
    ASSERT_EQ( n1,  0 );
    ASSERT_EQ( n2, 84 );
    ASSERT_EQ( n3,  0 );
}

TEST( CFPP_Number, OperatorLeftShiftEqual_T )
{
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< UInt64 >();
    
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorLeftShiftEqual_T< unsigned long long >();
}

TEST( CFPP_Number, OperatorRightShiftEqualNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 >>= CF::Number( 1 );
        n2 >>= CF::Number( 1 );
        n3 >>= CF::Number( 1 );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 21 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 >>= n3;
        n2 >>= n3;
        n3 >>= n3;
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

TEST( CFPP_Number, OperatorRightShiftEqualCFType )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 >>= static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() );
        n2 >>= static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() );
        n3 >>= static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 21 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 >>= static_cast< CFTypeRef >( n3.GetCFObject() );
        n2 >>= static_cast< CFTypeRef >( n3.GetCFObject() );
        n3 >>= static_cast< CFTypeRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 >>= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n2 >>= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        n3 >>= static_cast< CFTypeRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

TEST( CFPP_Number, OperatorRightShiftEqualCFNumber )
{
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 >>= static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() );
        n2 >>= static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() );
        n3 >>= static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 21 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 >>= static_cast< CFNumberRef >( n3.GetCFObject() );
        n2 >>= static_cast< CFNumberRef >( n3.GetCFObject() );
        n3 >>= static_cast< CFNumberRef >( n3.GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
    
    {
        CF::Number n1;
        CF::Number n2( 42 );
        CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
        
        n1 >>= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n2 >>= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        n3 >>= static_cast< CFNumberRef >( CF::Array().GetCFObject() );
        
        ASSERT_EQ( n1,  0 );
        ASSERT_EQ( n2, 42 );
        ASSERT_EQ( n3,  0 );
    }
}

template< typename T >
void TMPL_CFPP_Number_OperatorRightShiftEqual_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    n1 >>= static_cast< T >( 1 );
    n2 >>= static_cast< T >( 1 );
    n3 >>= static_cast< T >( 1 );
    
    ASSERT_EQ( n1,  0 );
    ASSERT_EQ( n2, 21 );
    ASSERT_EQ( n3,  0 );
}

TEST( CFPP_Number, OperatorRightShiftEqual_T )
{
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< SInt8 >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< SInt16 >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< SInt32 >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< SInt64 >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< UInt8 >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< UInt16 >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< UInt32 >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< UInt64 >();
    
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< signed char >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< signed short >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< signed int >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< signed long >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< signed long long >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< unsigned char >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< unsigned short >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< unsigned int >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< unsigned long >();
    TMPL_CFPP_Number_OperatorRightShiftEqual_T< unsigned long long >();
}

TEST( CFPP_Number, OperatorPlusNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 + CF::Number( 10 ), 10 );
    ASSERT_EQ( n2 + CF::Number( 10 ), 52 );
    ASSERT_EQ( n3 + CF::Number( 10 ), 10 );
    
    ASSERT_EQ( n1 + n3,  0 );
    ASSERT_EQ( n2 + n3, 42 );
    ASSERT_EQ( n3 + n3,  0 );
}

TEST( CFPP_Number, OperatorPlusCFType )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 + static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ), 10 );
    ASSERT_EQ( n2 + static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ), 52 );
    ASSERT_EQ( n3 + static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ), 10 );
    
    ASSERT_EQ( n1 + static_cast< CFTypeRef >( n3.GetCFObject() ),  0 );
    ASSERT_EQ( n2 + static_cast< CFTypeRef >( n3.GetCFObject() ), 42 );
    ASSERT_EQ( n3 + static_cast< CFTypeRef >( n3.GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 + static_cast< CFTypeRef >( CF::Array().GetCFObject() ),  0 );
    ASSERT_EQ( n2 + static_cast< CFTypeRef >( CF::Array().GetCFObject() ), 42 );
    ASSERT_EQ( n3 + static_cast< CFTypeRef >( CF::Array().GetCFObject() ),  0 );
}

TEST( CFPP_Number, OperatorPlusCFNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 + static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ), 10 );
    ASSERT_EQ( n2 + static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ), 52 );
    ASSERT_EQ( n3 + static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ), 10 );
    
    ASSERT_EQ( n1 + static_cast< CFNumberRef >( n3.GetCFObject() ),  0 );
    ASSERT_EQ( n2 + static_cast< CFNumberRef >( n3.GetCFObject() ), 42 );
    ASSERT_EQ( n3 + static_cast< CFNumberRef >( n3.GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 + static_cast< CFNumberRef >( CF::Array().GetCFObject() ),  0 );
    ASSERT_EQ( n2 + static_cast< CFNumberRef >( CF::Array().GetCFObject() ), 42 );
    ASSERT_EQ( n3 + static_cast< CFNumberRef >( CF::Array().GetCFObject() ),  0 );
}

template< typename T >
void TMPL_CFPP_Number_OperatorPlus_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 + static_cast< T >( 10 ), 10 );
    ASSERT_EQ( n2 + static_cast< T >( 10 ), 52 );
    ASSERT_EQ( n3 + static_cast< T >( 10 ), 10 );
}

TEST( CFPP_Number, OperatorPlus_T )
{
    TMPL_CFPP_Number_OperatorPlus_T< SInt8 >();
    TMPL_CFPP_Number_OperatorPlus_T< SInt16 >();
    TMPL_CFPP_Number_OperatorPlus_T< SInt32 >();
    TMPL_CFPP_Number_OperatorPlus_T< SInt64 >();
    TMPL_CFPP_Number_OperatorPlus_T< UInt8 >();
    TMPL_CFPP_Number_OperatorPlus_T< UInt16 >();
    TMPL_CFPP_Number_OperatorPlus_T< UInt32 >();
    TMPL_CFPP_Number_OperatorPlus_T< UInt64 >();
    TMPL_CFPP_Number_OperatorPlus_T< Float32 >();
    TMPL_CFPP_Number_OperatorPlus_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorPlus_T< signed char >();
    TMPL_CFPP_Number_OperatorPlus_T< signed short >();
    TMPL_CFPP_Number_OperatorPlus_T< signed int >();
    TMPL_CFPP_Number_OperatorPlus_T< signed long >();
    TMPL_CFPP_Number_OperatorPlus_T< signed long long >();
    TMPL_CFPP_Number_OperatorPlus_T< unsigned char >();
    TMPL_CFPP_Number_OperatorPlus_T< unsigned short >();
    TMPL_CFPP_Number_OperatorPlus_T< unsigned int >();
    TMPL_CFPP_Number_OperatorPlus_T< unsigned long >();
    TMPL_CFPP_Number_OperatorPlus_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorPlus_T< float >();
    TMPL_CFPP_Number_OperatorPlus_T< double >();
}

TEST( CFPP_Number, OperatorMinusNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 - CF::Number( 10 ), -10 );
    ASSERT_EQ( n2 - CF::Number( 10 ),  32 );
    ASSERT_EQ( n3 - CF::Number( 10 ), -10 );
    
    ASSERT_EQ( n1 - n3,  0 );
    ASSERT_EQ( n2 - n3, 42 );
    ASSERT_EQ( n3 - n3,  0 );
}

TEST( CFPP_Number, OperatorMinusCFType )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 - static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ), -10 );
    ASSERT_EQ( n2 - static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ),  32 );
    ASSERT_EQ( n3 - static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ), -10 );
    
    ASSERT_EQ( n1 - static_cast< CFTypeRef >( n3.GetCFObject() ),  0 );
    ASSERT_EQ( n2 - static_cast< CFTypeRef >( n3.GetCFObject() ), 42 );
    ASSERT_EQ( n3 - static_cast< CFTypeRef >( n3.GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 - static_cast< CFTypeRef >( CF::Array().GetCFObject() ),  0 );
    ASSERT_EQ( n2 - static_cast< CFTypeRef >( CF::Array().GetCFObject() ), 42 );
    ASSERT_EQ( n3 - static_cast< CFTypeRef >( CF::Array().GetCFObject() ),  0 );
}

TEST( CFPP_Number, OperatorMinusCFNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 - static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ), -10 );
    ASSERT_EQ( n2 - static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ),  32 );
    ASSERT_EQ( n3 - static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ), -10 );
    
    ASSERT_EQ( n1 - static_cast< CFNumberRef >( n3.GetCFObject() ),  0 );
    ASSERT_EQ( n2 - static_cast< CFNumberRef >( n3.GetCFObject() ), 42 );
    ASSERT_EQ( n3 - static_cast< CFNumberRef >( n3.GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 - static_cast< CFNumberRef >( CF::Array().GetCFObject() ),  0 );
    ASSERT_EQ( n2 - static_cast< CFNumberRef >( CF::Array().GetCFObject() ), 42 );
    ASSERT_EQ( n3 - static_cast< CFNumberRef >( CF::Array().GetCFObject() ),  0 );
}

template< typename T >
void TMPL_CFPP_Number_OperatorMinus_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 - static_cast< T >( 10 ), -10 );
    ASSERT_EQ( n2 - static_cast< T >( 10 ),  32 );
    ASSERT_EQ( n3 - static_cast< T >( 10 ), -10 );
}

TEST( CFPP_Number, OperatorMinus_T )
{
    TMPL_CFPP_Number_OperatorMinus_T< SInt8 >();
    TMPL_CFPP_Number_OperatorMinus_T< SInt16 >();
    TMPL_CFPP_Number_OperatorMinus_T< SInt32 >();
    TMPL_CFPP_Number_OperatorMinus_T< SInt64 >();
    TMPL_CFPP_Number_OperatorMinus_T< UInt8 >();
    TMPL_CFPP_Number_OperatorMinus_T< UInt16 >();
    TMPL_CFPP_Number_OperatorMinus_T< UInt32 >();
    TMPL_CFPP_Number_OperatorMinus_T< UInt64 >();
    TMPL_CFPP_Number_OperatorMinus_T< Float32 >();
    TMPL_CFPP_Number_OperatorMinus_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorMinus_T< signed char >();
    TMPL_CFPP_Number_OperatorMinus_T< signed short >();
    TMPL_CFPP_Number_OperatorMinus_T< signed int >();
    TMPL_CFPP_Number_OperatorMinus_T< signed long >();
    TMPL_CFPP_Number_OperatorMinus_T< signed long long >();
    TMPL_CFPP_Number_OperatorMinus_T< unsigned char >();
    TMPL_CFPP_Number_OperatorMinus_T< unsigned short >();
    TMPL_CFPP_Number_OperatorMinus_T< unsigned int >();
    TMPL_CFPP_Number_OperatorMinus_T< unsigned long >();
    TMPL_CFPP_Number_OperatorMinus_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorMinus_T< float >();
    TMPL_CFPP_Number_OperatorMinus_T< double >();
}

TEST( CFPP_Number, OperatorMultiplyNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 * CF::Number( 10 ),   0 );
    ASSERT_EQ( n2 * CF::Number( 10 ), 420 );
    ASSERT_EQ( n3 * CF::Number( 10 ),   0 );
    
    ASSERT_EQ( n1 * n3, 0 );
    ASSERT_EQ( n2 * n3, 0 );
    ASSERT_EQ( n3 * n3, 0 );
}

TEST( CFPP_Number, OperatorMultiplyCFType )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 * static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ),   0 );
    ASSERT_EQ( n2 * static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ), 420 );
    ASSERT_EQ( n3 * static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ),   0 );
    
    ASSERT_EQ( n1 * static_cast< CFTypeRef >( n3.GetCFObject() ), 0 );
    ASSERT_EQ( n2 * static_cast< CFTypeRef >( n3.GetCFObject() ), 0 );
    ASSERT_EQ( n3 * static_cast< CFTypeRef >( n3.GetCFObject() ), 0 );
    
    ASSERT_EQ( n1 * static_cast< CFTypeRef >( CF::Array().GetCFObject() ), 0 );
    ASSERT_EQ( n2 * static_cast< CFTypeRef >( CF::Array().GetCFObject() ), 0 );
    ASSERT_EQ( n3 * static_cast< CFTypeRef >( CF::Array().GetCFObject() ), 0 );
}

TEST( CFPP_Number, OperatorMultiplyCFNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 * static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ),   0 );
    ASSERT_EQ( n2 * static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ), 420 );
    ASSERT_EQ( n3 * static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ),   0 );
    
    ASSERT_EQ( n1 * static_cast< CFNumberRef >( n3.GetCFObject() ), 0 );
    ASSERT_EQ( n2 * static_cast< CFNumberRef >( n3.GetCFObject() ), 0 );
    ASSERT_EQ( n3 * static_cast< CFNumberRef >( n3.GetCFObject() ), 0 );
    
    ASSERT_EQ( n1 * static_cast< CFNumberRef >( CF::Array().GetCFObject() ), 0 );
    ASSERT_EQ( n2 * static_cast< CFNumberRef >( CF::Array().GetCFObject() ), 0 );
    ASSERT_EQ( n3 * static_cast< CFNumberRef >( CF::Array().GetCFObject() ), 0 );
}

template< typename T >
void TMPL_CFPP_Number_OperatorMultiply_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 * static_cast< T >( 10 ),   0 );
    ASSERT_EQ( n2 * static_cast< T >( 10 ), 420 );
    ASSERT_EQ( n3 * static_cast< T >( 10 ),   0 );
}

TEST( CFPP_Number, OperatorMultiply_T )
{
    TMPL_CFPP_Number_OperatorMultiply_T< SInt8 >();
    TMPL_CFPP_Number_OperatorMultiply_T< SInt16 >();
    TMPL_CFPP_Number_OperatorMultiply_T< SInt32 >();
    TMPL_CFPP_Number_OperatorMultiply_T< SInt64 >();
    TMPL_CFPP_Number_OperatorMultiply_T< UInt8 >();
    TMPL_CFPP_Number_OperatorMultiply_T< UInt16 >();
    TMPL_CFPP_Number_OperatorMultiply_T< UInt32 >();
    TMPL_CFPP_Number_OperatorMultiply_T< UInt64 >();
    TMPL_CFPP_Number_OperatorMultiply_T< Float32 >();
    TMPL_CFPP_Number_OperatorMultiply_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorMultiply_T< signed char >();
    TMPL_CFPP_Number_OperatorMultiply_T< signed short >();
    TMPL_CFPP_Number_OperatorMultiply_T< signed int >();
    TMPL_CFPP_Number_OperatorMultiply_T< signed long >();
    TMPL_CFPP_Number_OperatorMultiply_T< signed long long >();
    TMPL_CFPP_Number_OperatorMultiply_T< unsigned char >();
    TMPL_CFPP_Number_OperatorMultiply_T< unsigned short >();
    TMPL_CFPP_Number_OperatorMultiply_T< unsigned int >();
    TMPL_CFPP_Number_OperatorMultiply_T< unsigned long >();
    TMPL_CFPP_Number_OperatorMultiply_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorMultiply_T< float >();
    TMPL_CFPP_Number_OperatorMultiply_T< double >();
}

TEST( CFPP_Number, OperatorDivideNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_TRUE( FloatIsEqual( n1 / CF::Number( 10 ), 0.0 ) );
    ASSERT_TRUE( FloatIsEqual( n2 / CF::Number( 10 ), 4.2 ) );
    ASSERT_TRUE( FloatIsEqual( n3 / CF::Number( 10 ), 0.0 ) );
    
    ASSERT_THROW( n1 / n3, std::runtime_error );
    ASSERT_THROW( n2 / n3, std::runtime_error );
    ASSERT_THROW( n3 / n3, std::runtime_error );
}

TEST( CFPP_Number, OperatorDivideCFType )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_TRUE( FloatIsEqual( n1 / static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ), 0.0 ) );
    ASSERT_TRUE( FloatIsEqual( n2 / static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ), 4.2 ) );
    ASSERT_TRUE( FloatIsEqual( n3 / static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ), 0.0 ) );
    
    ASSERT_THROW( n1 / static_cast< CFTypeRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 / static_cast< CFTypeRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 / static_cast< CFTypeRef >( n3.GetCFObject() ), std::runtime_error );
    
    ASSERT_THROW( n1 / static_cast< CFTypeRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 / static_cast< CFTypeRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 / static_cast< CFTypeRef >( CF::Array().GetCFObject() ), std::runtime_error );
}

TEST( CFPP_Number, OperatorDivideCFNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_TRUE( FloatIsEqual( n1 / static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ), 0.0 ) );
    ASSERT_TRUE( FloatIsEqual( n2 / static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ), 4.2 ) );
    ASSERT_TRUE( FloatIsEqual( n3 / static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ), 0.0 ) );
    
    ASSERT_THROW( n1 / static_cast< CFNumberRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 / static_cast< CFNumberRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 / static_cast< CFNumberRef >( n3.GetCFObject() ), std::runtime_error );
    
    ASSERT_THROW( n1 / static_cast< CFNumberRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 / static_cast< CFNumberRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 / static_cast< CFNumberRef >( CF::Array().GetCFObject() ), std::runtime_error );
}

template< typename T >
void TMPL_CFPP_Number_OperatorDivide_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_TRUE( FloatIsEqual( n1 / static_cast< T >( 10 ), 0.0 ) );
    ASSERT_TRUE( FloatIsEqual( n2 / static_cast< T >( 10 ), 4.2 ) );
    ASSERT_TRUE( FloatIsEqual( n3 / static_cast< T >( 10 ), 0.0 ) );
    
    ASSERT_THROW( n1 / static_cast< T >( 0 ), std::runtime_error );
    ASSERT_THROW( n2 / static_cast< T >( 0 ), std::runtime_error );
    ASSERT_THROW( n3 / static_cast< T >( 0 ), std::runtime_error );
}

TEST( CFPP_Number, OperatorDivide_T )
{
    TMPL_CFPP_Number_OperatorDivide_T< SInt8 >();
    TMPL_CFPP_Number_OperatorDivide_T< SInt16 >();
    TMPL_CFPP_Number_OperatorDivide_T< SInt32 >();
    TMPL_CFPP_Number_OperatorDivide_T< SInt64 >();
    TMPL_CFPP_Number_OperatorDivide_T< UInt8 >();
    TMPL_CFPP_Number_OperatorDivide_T< UInt16 >();
    TMPL_CFPP_Number_OperatorDivide_T< UInt32 >();
    TMPL_CFPP_Number_OperatorDivide_T< UInt64 >();
    TMPL_CFPP_Number_OperatorDivide_T< Float32 >();
    TMPL_CFPP_Number_OperatorDivide_T< Float64 >();
    
    TMPL_CFPP_Number_OperatorDivide_T< signed char >();
    TMPL_CFPP_Number_OperatorDivide_T< signed short >();
    TMPL_CFPP_Number_OperatorDivide_T< signed int >();
    TMPL_CFPP_Number_OperatorDivide_T< signed long >();
    TMPL_CFPP_Number_OperatorDivide_T< signed long long >();
    TMPL_CFPP_Number_OperatorDivide_T< unsigned char >();
    TMPL_CFPP_Number_OperatorDivide_T< unsigned short >();
    TMPL_CFPP_Number_OperatorDivide_T< unsigned int >();
    TMPL_CFPP_Number_OperatorDivide_T< unsigned long >();
    TMPL_CFPP_Number_OperatorDivide_T< unsigned long long >();
    TMPL_CFPP_Number_OperatorDivide_T< float >();
    TMPL_CFPP_Number_OperatorDivide_T< double >();
}

TEST( CFPP_Number, OperatorModNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 % CF::Number( 10 ), 0 );
    ASSERT_EQ( n2 % CF::Number( 10 ), 2 );
    ASSERT_EQ( n3 % CF::Number( 10 ), 0 );
    
    ASSERT_THROW( n1 % n3, std::runtime_error );
    ASSERT_THROW( n2 % n3, std::runtime_error );
    ASSERT_THROW( n3 % n3, std::runtime_error );
}

TEST( CFPP_Number, OperatorModCFType )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 % static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ), 0 );
    ASSERT_EQ( n2 % static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ), 2 );
    ASSERT_EQ( n3 % static_cast< CFTypeRef >( CF::Number( 10 ).GetCFObject() ), 0 );
    
    ASSERT_THROW( n1 % static_cast< CFTypeRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 % static_cast< CFTypeRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 % static_cast< CFTypeRef >( n3.GetCFObject() ), std::runtime_error );
    
    ASSERT_THROW( n1 % static_cast< CFTypeRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 % static_cast< CFTypeRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 % static_cast< CFTypeRef >( CF::Array().GetCFObject() ), std::runtime_error );
}

TEST( CFPP_Number, OperatorModCFNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 % static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ), 0 );
    ASSERT_EQ( n2 % static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ), 2 );
    ASSERT_EQ( n3 % static_cast< CFNumberRef >( CF::Number( 10 ).GetCFObject() ), 0 );
    
    ASSERT_THROW( n1 % static_cast< CFNumberRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 % static_cast< CFNumberRef >( n3.GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 % static_cast< CFNumberRef >( n3.GetCFObject() ), std::runtime_error );
    
    ASSERT_THROW( n1 % static_cast< CFNumberRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n2 % static_cast< CFNumberRef >( CF::Array().GetCFObject() ), std::runtime_error );
    ASSERT_THROW( n3 % static_cast< CFNumberRef >( CF::Array().GetCFObject() ), std::runtime_error );
}

template< typename T >
void TMPL_CFPP_Number_OperatorMod_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 % static_cast< T >( 10 ), 0 );
    ASSERT_EQ( n2 % static_cast< T >( 10 ), 2 );
    ASSERT_EQ( n3 % static_cast< T >( 10 ), 0 );
    
    ASSERT_THROW( n1 % static_cast< T >( 0 ), std::runtime_error );
    ASSERT_THROW( n2 % static_cast< T >( 0 ), std::runtime_error );
    ASSERT_THROW( n3 % static_cast< T >( 0 ), std::runtime_error );
}

TEST( CFPP_Number, OperatorMod_T )
{
    TMPL_CFPP_Number_OperatorMod_T< SInt8 >();
    TMPL_CFPP_Number_OperatorMod_T< SInt16 >();
    TMPL_CFPP_Number_OperatorMod_T< SInt32 >();
    TMPL_CFPP_Number_OperatorMod_T< SInt64 >();
    TMPL_CFPP_Number_OperatorMod_T< UInt8 >();
    TMPL_CFPP_Number_OperatorMod_T< UInt16 >();
    TMPL_CFPP_Number_OperatorMod_T< UInt32 >();
    TMPL_CFPP_Number_OperatorMod_T< UInt64 >();
    
    TMPL_CFPP_Number_OperatorMod_T< signed char >();
    TMPL_CFPP_Number_OperatorMod_T< signed short >();
    TMPL_CFPP_Number_OperatorMod_T< signed int >();
    TMPL_CFPP_Number_OperatorMod_T< signed long >();
    TMPL_CFPP_Number_OperatorMod_T< signed long long >();
    TMPL_CFPP_Number_OperatorMod_T< unsigned char >();
    TMPL_CFPP_Number_OperatorMod_T< unsigned short >();
    TMPL_CFPP_Number_OperatorMod_T< unsigned int >();
    TMPL_CFPP_Number_OperatorMod_T< unsigned long >();
    TMPL_CFPP_Number_OperatorMod_T< unsigned long long >();
}

TEST( CFPP_Number, OperatorBitwiseAndNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 & CF::Number( 12 ), 0 );
    ASSERT_EQ( n2 & CF::Number( 12 ), 8 );
    ASSERT_EQ( n3 & CF::Number( 12 ), 0 );
    
    ASSERT_EQ( n1 & n3, 0 );
    ASSERT_EQ( n2 & n3, 0 );
    ASSERT_EQ( n3 & n3, 0 );
}

TEST( CFPP_Number, OperatorBitwiseAndCFType )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 & static_cast< CFTypeRef >( CF::Number( 12 ).GetCFObject() ), 0 );
    ASSERT_EQ( n2 & static_cast< CFTypeRef >( CF::Number( 12 ).GetCFObject() ), 8 );
    ASSERT_EQ( n3 & static_cast< CFTypeRef >( CF::Number( 12 ).GetCFObject() ), 0 );
    
    ASSERT_EQ( n1 & static_cast< CFTypeRef >( n3.GetCFObject() ), 0 );
    ASSERT_EQ( n2 & static_cast< CFTypeRef >( n3.GetCFObject() ), 0 );
    ASSERT_EQ( n3 & static_cast< CFTypeRef >( n3.GetCFObject() ), 0 );
    
    ASSERT_EQ( n1 & static_cast< CFTypeRef >( CF::Array().GetCFObject() ), 0 );
    ASSERT_EQ( n2 & static_cast< CFTypeRef >( CF::Array().GetCFObject() ), 0 );
    ASSERT_EQ( n3 & static_cast< CFTypeRef >( CF::Array().GetCFObject() ), 0 );
}

TEST( CFPP_Number, OperatorBitwiseAndCFNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 & static_cast< CFNumberRef >( CF::Number( 12 ).GetCFObject() ), 0 );
    ASSERT_EQ( n2 & static_cast< CFNumberRef >( CF::Number( 12 ).GetCFObject() ), 8 );
    ASSERT_EQ( n3 & static_cast< CFNumberRef >( CF::Number( 12 ).GetCFObject() ), 0 );
    
    ASSERT_EQ( n1 & static_cast< CFNumberRef >( n3.GetCFObject() ), 0 );
    ASSERT_EQ( n2 & static_cast< CFNumberRef >( n3.GetCFObject() ), 0 );
    ASSERT_EQ( n3 & static_cast< CFNumberRef >( n3.GetCFObject() ), 0 );
    
    ASSERT_EQ( n1 & static_cast< CFNumberRef >( CF::Array().GetCFObject() ), 0 );
    ASSERT_EQ( n2 & static_cast< CFNumberRef >( CF::Array().GetCFObject() ), 0 );
    ASSERT_EQ( n3 & static_cast< CFNumberRef >( CF::Array().GetCFObject() ), 0 );
}

template< typename T >
void TMPL_CFPP_Number_OperatorBiwiseAnd_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 & static_cast< T >( 12 ), 0 );
    ASSERT_EQ( n2 & static_cast< T >( 12 ), 8 );
    ASSERT_EQ( n3 & static_cast< T >( 12 ), 0 );
}

TEST( CFPP_Number, OperatorBitwiseAnd_T )
{
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< SInt8 >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< SInt16 >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< SInt32 >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< SInt64 >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< UInt8 >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< UInt16 >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< UInt32 >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< UInt64 >();
    
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< signed char >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< signed short >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< signed int >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< signed long >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< signed long long >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< unsigned char >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< unsigned short >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< unsigned int >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< unsigned long >();
    TMPL_CFPP_Number_OperatorBiwiseAnd_T< unsigned long long >();
}

TEST( CFPP_Number, OperatorBitwiseOrNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 | CF::Number( 21 ), 21 );
    ASSERT_EQ( n2 | CF::Number( 21 ), 63 );
    ASSERT_EQ( n3 | CF::Number( 21 ), 21 );
    
    ASSERT_EQ( n1 | n3,  0 );
    ASSERT_EQ( n2 | n3, 42 );
    ASSERT_EQ( n3 | n3,  0 );
}

TEST( CFPP_Number, OperatorBitwiseOrCFType )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 | static_cast< CFTypeRef >( CF::Number( 21 ).GetCFObject() ), 21 );
    ASSERT_EQ( n2 | static_cast< CFTypeRef >( CF::Number( 21 ).GetCFObject() ), 63 );
    ASSERT_EQ( n3 | static_cast< CFTypeRef >( CF::Number( 21 ).GetCFObject() ), 21 );
    
    ASSERT_EQ( n1 | static_cast< CFTypeRef >( n3.GetCFObject() ),  0 );
    ASSERT_EQ( n2 | static_cast< CFTypeRef >( n3.GetCFObject() ), 42 );
    ASSERT_EQ( n3 | static_cast< CFTypeRef >( n3.GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 | static_cast< CFTypeRef >( CF::Array().GetCFObject() ),  0 );
    ASSERT_EQ( n2 | static_cast< CFTypeRef >( CF::Array().GetCFObject() ), 42 );
    ASSERT_EQ( n3 | static_cast< CFTypeRef >( CF::Array().GetCFObject() ),  0 );
}

TEST( CFPP_Number, OperatorBitwiseOrCFNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 | static_cast< CFNumberRef >( CF::Number( 21 ).GetCFObject() ), 21 );
    ASSERT_EQ( n2 | static_cast< CFNumberRef >( CF::Number( 21 ).GetCFObject() ), 63 );
    ASSERT_EQ( n3 | static_cast< CFNumberRef >( CF::Number( 21 ).GetCFObject() ), 21 );
    
    ASSERT_EQ( n1 | static_cast< CFNumberRef >( n3.GetCFObject() ),  0 );
    ASSERT_EQ( n2 | static_cast< CFNumberRef >( n3.GetCFObject() ), 42 );
    ASSERT_EQ( n3 | static_cast< CFNumberRef >( n3.GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 | static_cast< CFNumberRef >( CF::Array().GetCFObject() ),  0 );
    ASSERT_EQ( n2 | static_cast< CFNumberRef >( CF::Array().GetCFObject() ), 42 );
    ASSERT_EQ( n3 | static_cast< CFNumberRef >( CF::Array().GetCFObject() ),  0 );
}

template< typename T >
void TMPL_CFPP_Number_OperatorBiwiseOr_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 | static_cast< T >( 21 ), 21 );
    ASSERT_EQ( n2 | static_cast< T >( 21 ), 63 );
    ASSERT_EQ( n3 | static_cast< T >( 21 ), 21 );
}

TEST( CFPP_Number, OperatorBitwiseOr_T )
{
    TMPL_CFPP_Number_OperatorBiwiseOr_T< SInt8 >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< SInt16 >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< SInt32 >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< SInt64 >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< UInt8 >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< UInt16 >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< UInt32 >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< UInt64 >();
    
    TMPL_CFPP_Number_OperatorBiwiseOr_T< signed char >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< signed short >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< signed int >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< signed long >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< signed long long >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< unsigned char >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< unsigned short >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< unsigned int >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< unsigned long >();
    TMPL_CFPP_Number_OperatorBiwiseOr_T< unsigned long long >();
}

TEST( CFPP_Number, OperatorXorNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 ^ CF::Number( 43 ), 43 );
    ASSERT_EQ( n2 ^ CF::Number( 43 ),  1 );
    ASSERT_EQ( n3 ^ CF::Number( 43 ), 43 );
    
    ASSERT_EQ( n1 ^ n3,  0 );
    ASSERT_EQ( n2 ^ n3, 42 );
    ASSERT_EQ( n3 ^ n3,  0 );
}

TEST( CFPP_Number, OperatorXorCFType )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 ^ static_cast< CFTypeRef >( CF::Number( 43 ).GetCFObject() ), 43 );
    ASSERT_EQ( n2 ^ static_cast< CFTypeRef >( CF::Number( 43 ).GetCFObject() ),  1 );
    ASSERT_EQ( n3 ^ static_cast< CFTypeRef >( CF::Number( 43 ).GetCFObject() ), 43 );
    
    ASSERT_EQ( n1 ^ static_cast< CFTypeRef >( n3.GetCFObject() ),  0 );
    ASSERT_EQ( n2 ^ static_cast< CFTypeRef >( n3.GetCFObject() ), 42 );
    ASSERT_EQ( n3 ^ static_cast< CFTypeRef >( n3.GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 ^ static_cast< CFTypeRef >( CF::Array().GetCFObject() ),  0 );
    ASSERT_EQ( n2 ^ static_cast< CFTypeRef >( CF::Array().GetCFObject() ), 42 );
    ASSERT_EQ( n3 ^ static_cast< CFTypeRef >( CF::Array().GetCFObject() ),  0 );
}

TEST( CFPP_Number, OperatorXorCFNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 ^ static_cast< CFNumberRef >( CF::Number( 43 ).GetCFObject() ), 43 );
    ASSERT_EQ( n2 ^ static_cast< CFNumberRef >( CF::Number( 43 ).GetCFObject() ),  1 );
    ASSERT_EQ( n3 ^ static_cast< CFNumberRef >( CF::Number( 43 ).GetCFObject() ), 43 );
    
    ASSERT_EQ( n1 ^ static_cast< CFNumberRef >( n3.GetCFObject() ),  0 );
    ASSERT_EQ( n2 ^ static_cast< CFNumberRef >( n3.GetCFObject() ), 42 );
    ASSERT_EQ( n3 ^ static_cast< CFNumberRef >( n3.GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 ^ static_cast< CFNumberRef >( CF::Array().GetCFObject() ),  0 );
    ASSERT_EQ( n2 ^ static_cast< CFNumberRef >( CF::Array().GetCFObject() ), 42 );
    ASSERT_EQ( n3 ^ static_cast< CFNumberRef >( CF::Array().GetCFObject() ),  0 );
}

template< typename T >
void TMPL_CFPP_Number_OperatorXor_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 ^ static_cast< T >( 43 ), 43 );
    ASSERT_EQ( n2 ^ static_cast< T >( 43 ),  1 );
    ASSERT_EQ( n3 ^ static_cast< T >( 43 ), 43 );
}

TEST( CFPP_Number, OperatorXor_T )
{
    TMPL_CFPP_Number_OperatorXor_T< SInt8 >();
    TMPL_CFPP_Number_OperatorXor_T< SInt16 >();
    TMPL_CFPP_Number_OperatorXor_T< SInt32 >();
    TMPL_CFPP_Number_OperatorXor_T< SInt64 >();
    TMPL_CFPP_Number_OperatorXor_T< UInt8 >();
    TMPL_CFPP_Number_OperatorXor_T< UInt16 >();
    TMPL_CFPP_Number_OperatorXor_T< UInt32 >();
    TMPL_CFPP_Number_OperatorXor_T< UInt64 >();
    
    TMPL_CFPP_Number_OperatorXor_T< signed char >();
    TMPL_CFPP_Number_OperatorXor_T< signed short >();
    TMPL_CFPP_Number_OperatorXor_T< signed int >();
    TMPL_CFPP_Number_OperatorXor_T< signed long >();
    TMPL_CFPP_Number_OperatorXor_T< signed long long >();
    TMPL_CFPP_Number_OperatorXor_T< unsigned char >();
    TMPL_CFPP_Number_OperatorXor_T< unsigned short >();
    TMPL_CFPP_Number_OperatorXor_T< unsigned int >();
    TMPL_CFPP_Number_OperatorXor_T< unsigned long >();
    TMPL_CFPP_Number_OperatorXor_T< unsigned long long >();
}

TEST( CFPP_Number, OperatorLeftShiftNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 << CF::Number( 1 ),  0 );
    ASSERT_EQ( n2 << CF::Number( 1 ), 84 );
    ASSERT_EQ( n3 << CF::Number( 1 ),  0 );
    
    ASSERT_EQ( n1 << n3,  0 );
    ASSERT_EQ( n2 << n3, 42 );
    ASSERT_EQ( n3 << n3,  0 );
}

TEST( CFPP_Number, OperatorLeftShiftCFType )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 << static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() ),  0 );
    ASSERT_EQ( n2 << static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() ), 84 );
    ASSERT_EQ( n3 << static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 << static_cast< CFTypeRef >( n3.GetCFObject() ),  0 );
    ASSERT_EQ( n2 << static_cast< CFTypeRef >( n3.GetCFObject() ), 42 );
    ASSERT_EQ( n3 << static_cast< CFTypeRef >( n3.GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 << static_cast< CFTypeRef >( CF::Array().GetCFObject() ),  0 );
    ASSERT_EQ( n2 << static_cast< CFTypeRef >( CF::Array().GetCFObject() ), 42 );
    ASSERT_EQ( n3 << static_cast< CFTypeRef >( CF::Array().GetCFObject() ),  0 );
}

TEST( CFPP_Number, OperatorLeftShiftCFNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 << static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() ),  0 );
    ASSERT_EQ( n2 << static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() ), 84 );
    ASSERT_EQ( n3 << static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 << static_cast< CFNumberRef >( n3.GetCFObject() ),  0 );
    ASSERT_EQ( n2 << static_cast< CFNumberRef >( n3.GetCFObject() ), 42 );
    ASSERT_EQ( n3 << static_cast< CFNumberRef >( n3.GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 << static_cast< CFNumberRef >( CF::Array().GetCFObject() ),  0 );
    ASSERT_EQ( n2 << static_cast< CFNumberRef >( CF::Array().GetCFObject() ), 42 );
    ASSERT_EQ( n3 << static_cast< CFNumberRef >( CF::Array().GetCFObject() ),  0 );
}

template< typename T >
void TMPL_CFPP_Number_OperatorLeftShift_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 << static_cast< T >( 1 ),  0 );
    ASSERT_EQ( n2 << static_cast< T >( 1 ), 84 );
    ASSERT_EQ( n3 << static_cast< T >( 1 ),  0 );
}

TEST( CFPP_Number, OperatorLeftShift_T )
{
    TMPL_CFPP_Number_OperatorLeftShift_T< SInt8 >();
    TMPL_CFPP_Number_OperatorLeftShift_T< SInt16 >();
    TMPL_CFPP_Number_OperatorLeftShift_T< SInt32 >();
    TMPL_CFPP_Number_OperatorLeftShift_T< SInt64 >();
    TMPL_CFPP_Number_OperatorLeftShift_T< UInt8 >();
    TMPL_CFPP_Number_OperatorLeftShift_T< UInt16 >();
    TMPL_CFPP_Number_OperatorLeftShift_T< UInt32 >();
    TMPL_CFPP_Number_OperatorLeftShift_T< UInt64 >();
    
    TMPL_CFPP_Number_OperatorLeftShift_T< signed char >();
    TMPL_CFPP_Number_OperatorLeftShift_T< signed short >();
    TMPL_CFPP_Number_OperatorLeftShift_T< signed int >();
    TMPL_CFPP_Number_OperatorLeftShift_T< signed long >();
    TMPL_CFPP_Number_OperatorLeftShift_T< signed long long >();
    TMPL_CFPP_Number_OperatorLeftShift_T< unsigned char >();
    TMPL_CFPP_Number_OperatorLeftShift_T< unsigned short >();
    TMPL_CFPP_Number_OperatorLeftShift_T< unsigned int >();
    TMPL_CFPP_Number_OperatorLeftShift_T< unsigned long >();
    TMPL_CFPP_Number_OperatorLeftShift_T< unsigned long long >();
}

TEST( CFPP_Number, OperatorRightShiftNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 >> CF::Number( 1 ),  0 );
    ASSERT_EQ( n2 >> CF::Number( 1 ), 21 );
    ASSERT_EQ( n3 >> CF::Number( 1 ),  0 );
    
    ASSERT_EQ( n1 >> n3,  0 );
    ASSERT_EQ( n2 >> n3, 42 );
    ASSERT_EQ( n3 >> n3,  0 );
}

TEST( CFPP_Number, OperatorRightShiftCFType )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 >> static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() ),  0 );
    ASSERT_EQ( n2 >> static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() ), 21 );
    ASSERT_EQ( n3 >> static_cast< CFTypeRef >( CF::Number( 1 ).GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 >> static_cast< CFTypeRef >( n3.GetCFObject() ),  0 );
    ASSERT_EQ( n2 >> static_cast< CFTypeRef >( n3.GetCFObject() ), 42 );
    ASSERT_EQ( n3 >> static_cast< CFTypeRef >( n3.GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 >> static_cast< CFTypeRef >( CF::Array().GetCFObject() ),  0 );
    ASSERT_EQ( n2 >> static_cast< CFTypeRef >( CF::Array().GetCFObject() ), 42 );
    ASSERT_EQ( n3 >> static_cast< CFTypeRef >( CF::Array().GetCFObject() ),  0 );
}

TEST( CFPP_Number, OperatorRightShiftCFNumber )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 >> static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() ),  0 );
    ASSERT_EQ( n2 >> static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() ), 21 );
    ASSERT_EQ( n3 >> static_cast< CFNumberRef >( CF::Number( 1 ).GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 >> static_cast< CFNumberRef >( n3.GetCFObject() ),  0 );
    ASSERT_EQ( n2 >> static_cast< CFNumberRef >( n3.GetCFObject() ), 42 );
    ASSERT_EQ( n3 >> static_cast< CFNumberRef >( n3.GetCFObject() ),  0 );
    
    ASSERT_EQ( n1 >> static_cast< CFNumberRef >( CF::Array().GetCFObject() ),  0 );
    ASSERT_EQ( n2 >> static_cast< CFNumberRef >( CF::Array().GetCFObject() ), 42 );
    ASSERT_EQ( n3 >> static_cast< CFNumberRef >( CF::Array().GetCFObject() ),  0 );
}

template< typename T >
void TMPL_CFPP_Number_OperatorRightShift_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( n1 >> static_cast< T >( 1 ),  0 );
    ASSERT_EQ( n2 >> static_cast< T >( 1 ), 21 );
    ASSERT_EQ( n3 >> static_cast< T >( 1 ),  0 );
}

TEST( CFPP_Number, OperatorRightShift_T )
{
    TMPL_CFPP_Number_OperatorRightShift_T< SInt8 >();
    TMPL_CFPP_Number_OperatorRightShift_T< SInt16 >();
    TMPL_CFPP_Number_OperatorRightShift_T< SInt32 >();
    TMPL_CFPP_Number_OperatorRightShift_T< SInt64 >();
    TMPL_CFPP_Number_OperatorRightShift_T< UInt8 >();
    TMPL_CFPP_Number_OperatorRightShift_T< UInt16 >();
    TMPL_CFPP_Number_OperatorRightShift_T< UInt32 >();
    TMPL_CFPP_Number_OperatorRightShift_T< UInt64 >();
    
    TMPL_CFPP_Number_OperatorRightShift_T< signed char >();
    TMPL_CFPP_Number_OperatorRightShift_T< signed short >();
    TMPL_CFPP_Number_OperatorRightShift_T< signed int >();
    TMPL_CFPP_Number_OperatorRightShift_T< signed long >();
    TMPL_CFPP_Number_OperatorRightShift_T< signed long long >();
    TMPL_CFPP_Number_OperatorRightShift_T< unsigned char >();
    TMPL_CFPP_Number_OperatorRightShift_T< unsigned short >();
    TMPL_CFPP_Number_OperatorRightShift_T< unsigned int >();
    TMPL_CFPP_Number_OperatorRightShift_T< unsigned long >();
    TMPL_CFPP_Number_OperatorRightShift_T< unsigned long long >();
}

template< typename T >
void TMPL_CFPP_Number_CastTo_T()
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_EQ( static_cast< T >( n1 ), static_cast< T >(  0 ) );
    ASSERT_EQ( static_cast< T >( n2 ), static_cast< T >( 42 ) );
    ASSERT_EQ( static_cast< T >( n3 ), static_cast< T >(  0 ) );
}

TEST( CFPP_Number, CastTo_T )
{
    TMPL_CFPP_Number_CastTo_T< SInt8 >();
    TMPL_CFPP_Number_CastTo_T< SInt16 >();
    TMPL_CFPP_Number_CastTo_T< SInt32 >();
    TMPL_CFPP_Number_CastTo_T< SInt64 >();
    TMPL_CFPP_Number_CastTo_T< UInt8 >();
    TMPL_CFPP_Number_CastTo_T< UInt16 >();
    TMPL_CFPP_Number_CastTo_T< UInt32 >();
    TMPL_CFPP_Number_CastTo_T< UInt64 >();
    
    TMPL_CFPP_Number_CastTo_T< signed char >();
    TMPL_CFPP_Number_CastTo_T< signed short >();
    TMPL_CFPP_Number_CastTo_T< signed int >();
    TMPL_CFPP_Number_CastTo_T< signed long >();
    TMPL_CFPP_Number_CastTo_T< signed long long >();
    TMPL_CFPP_Number_CastTo_T< unsigned char >();
    TMPL_CFPP_Number_CastTo_T< unsigned short >();
    TMPL_CFPP_Number_CastTo_T< unsigned int >();
    TMPL_CFPP_Number_CastTo_T< unsigned long >();
    TMPL_CFPP_Number_CastTo_T< unsigned long long >();
}

TEST( CFPP_Number, CastToFloat32 )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_TRUE( FloatIsEqual( static_cast< Float32 >( n1 ),  0 ) );
    ASSERT_TRUE( FloatIsEqual( static_cast< Float32 >( n2 ), 42 ) );
    ASSERT_TRUE( FloatIsEqual( static_cast< Float32 >( n3 ),  0 ) );
}

TEST( CFPP_Number, CastToFloat64 )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_TRUE( FloatIsEqual( static_cast< Float64 >( n1 ),  0 ) );
    ASSERT_TRUE( FloatIsEqual( static_cast< Float64 >( n2 ), 42 ) );
    ASSERT_TRUE( FloatIsEqual( static_cast< Float64 >( n3 ),  0 ) );
}

TEST( CFPP_Number, GetTypeID )
{
    CF::Number n;
    
    ASSERT_EQ( n.GetTypeID(), CFNumberGetTypeID() );
}

TEST( CFPP_Number, GetCFObject )
{
    CF::Number n1;
    CF::Number n2( 42 );
    CF::Number n3( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_TRUE( n1.GetCFObject() != nullptr );
    ASSERT_TRUE( n2.GetCFObject() != nullptr );
    ASSERT_TRUE( n3.GetCFObject() == nullptr );
    ASSERT_EQ( CFGetTypeID( n1.GetCFObject() ), CFNumberGetTypeID() );
    ASSERT_EQ( CFGetTypeID( n2.GetCFObject() ), CFNumberGetTypeID() );
}

TEST( CFPP_Number, IsFloatType )
{
    CF::Number n1;
    CF::Number n2( static_cast< UInt8 >( 42 ) );
    CF::Number n3( static_cast< Float32 >( 42 ) );
    CF::Number n4( static_cast< CFNumberRef >( nullptr ) );
    
    ASSERT_FALSE( n1.IsFloatType() );
    ASSERT_FALSE( n2.IsFloatType() );
    ASSERT_TRUE(  n3.IsFloatType() );
    ASSERT_FALSE( n4.IsFloatType() );
}

TEST( CFPP_Number, GetSignedCharValue )
{
    CF::Number n( 42 );
    
    ASSERT_EQ( n.GetSignedCharValue(), static_cast< char >( 42 ) );
    
    n = static_cast< CFNumberRef >( nullptr );
    
    ASSERT_FALSE( n.IsValid() );
    ASSERT_EQ( n.GetSignedCharValue(), static_cast< char >( 0 ) );
}

TEST( CFPP_Number, GetSignedShortValue )
{
    CF::Number n( 42 );
    
    ASSERT_EQ( n.GetSignedShortValue(), static_cast< short >( 42 ) );
    
    n = static_cast< CFNumberRef >( nullptr );
    
    ASSERT_FALSE( n.IsValid() );
    ASSERT_EQ( n.GetSignedShortValue(), static_cast< short >( 0 ) );
}

TEST( CFPP_Number, GetSignedIntValue )
{
    CF::Number n( 42 );
    
    ASSERT_EQ( n.GetSignedIntValue(), static_cast< int >( 42 ) );
    
    n = static_cast< CFNumberRef >( nullptr );
    
    ASSERT_FALSE( n.IsValid() );
    ASSERT_EQ( n.GetSignedIntValue(), static_cast< int >( 0 ) );
}

TEST( CFPP_Number, GetSignedLongValue )
{
    CF::Number n( 42 );
    
    ASSERT_EQ( n.GetSignedLongValue(), static_cast< long >( 42 ) );
    
    n = static_cast< CFNumberRef >( nullptr );
    
    ASSERT_FALSE( n.IsValid() );
    ASSERT_EQ( n.GetSignedLongValue(), static_cast< long >( 0 ) );
}

TEST( CFPP_Number, GetSignedLongLongValue )
{
	CF::Number n( 42 );

	ASSERT_EQ( n.GetSignedLongLongValue(), static_cast< long long >( 42 ) );

	n = static_cast< CFNumberRef >( nullptr );

	ASSERT_FALSE( n.IsValid() );
	ASSERT_EQ( n.GetSignedLongLongValue(), static_cast< long long >( 0 ) );
}

TEST( CFPP_Number, GetUnsignedCharValue )
{
    CF::Number n( 42 );
    
    ASSERT_EQ( n.GetUnsignedCharValue(), static_cast< unsigned char >( 42 ) );
    
    n = static_cast< CFNumberRef >( nullptr );
    
    ASSERT_FALSE( n.IsValid() );
    ASSERT_EQ( n.GetUnsignedCharValue(), static_cast< unsigned char >( 0 ) );
}

TEST( CFPP_Number, GetUnsignedShortValue )
{
    CF::Number n( 42 );
    
    ASSERT_EQ( n.GetUnsignedShortValue(), static_cast< unsigned short >( 42 ) );
    
    n = static_cast< CFNumberRef >( nullptr );
    
    ASSERT_FALSE( n.IsValid() );
    ASSERT_EQ( n.GetUnsignedShortValue(), static_cast< unsigned short >( 0 ) );
}

TEST( CFPP_Number, GetUnsignedIntValue )
{
    CF::Number n( 42 );
    
    ASSERT_EQ( n.GetUnsignedIntValue(), static_cast< unsigned int >( 42 ) );
    
    n = static_cast< CFNumberRef >( nullptr );
    
    ASSERT_FALSE( n.IsValid() );
    ASSERT_EQ( n.GetUnsignedIntValue(), static_cast< unsigned int >( 0 ) );
}

TEST( CFPP_Number, GetUnsignedLongValue )
{
    CF::Number n( 42 );
    
    ASSERT_EQ( n.GetUnsignedLongValue(), static_cast< unsigned long >( 42 ) );
    
    n = static_cast< CFNumberRef >( nullptr );
    
    ASSERT_FALSE( n.IsValid() );
    ASSERT_EQ( n.GetUnsignedLongValue(), static_cast< unsigned long >( 0 ) );
}

TEST( CFPP_Number, GetUnsignedLongLongValue )
{
	CF::Number n( 42 );

	ASSERT_EQ( n.GetUnsignedLongLongValue(), static_cast< unsigned long long >( 42 ) );

	n = static_cast< CFNumberRef >( nullptr );

	ASSERT_FALSE( n.IsValid() );
	ASSERT_EQ( n.GetUnsignedLongLongValue(), static_cast< unsigned long long >( 0 ) );
}

TEST( CFPP_Number, GetFloatValue )
{
    CF::Number n( 42 );
    
    ASSERT_TRUE( FloatIsEqual( n.GetFloatValue(), 42 ) );
    
    n = static_cast< CFNumberRef >( nullptr );
    
    ASSERT_FALSE( n.IsValid() );
    ASSERT_TRUE( FloatIsEqual( n.GetFloatValue(), 0 ) );
}

TEST( CFPP_Number, GetDoubleValue )
{
    CF::Number n( 42 );
    
    ASSERT_TRUE( FloatIsEqual( n.GetDoubleValue(), 42 ) );
    
    n = static_cast< CFNumberRef >( nullptr );
    
    ASSERT_FALSE( n.IsValid() );
    ASSERT_TRUE( FloatIsEqual( n.GetDoubleValue(), 0 ) );
}

TEST( CFPP_Number, SetSignedCharValue )
{
    CF::Number n;
    
    n.SetSignedCharValue( 42 );
    
    ASSERT_EQ( n.GetSignedCharValue(), static_cast< signed char >( 42 ) );
}

TEST( CFPP_Number, SetSignedShortValue )
{
    CF::Number n;
    
    n.SetSignedShortValue( 42 );
    
    ASSERT_EQ( n.GetSignedShortValue(), static_cast< signed short >( 42 ) );
}

TEST( CFPP_Number, SetSignedIntValue )
{
    CF::Number n;
    
    n.SetSignedIntValue( 42 );
    
    ASSERT_EQ( n.GetSignedIntValue(), static_cast< signed int >( 42 ) );
}

TEST( CFPP_Number, SetSignedLongValue )
{
    CF::Number n;
    
    n.SetSignedLongValue( 42 );
    
    ASSERT_EQ( n.GetSignedLongValue(), static_cast< signed long >( 42 ) );
}

TEST( CFPP_Number, SetSignedLongLongValue )
{
	CF::Number n;

	n.SetSignedLongLongValue( 42 );

	ASSERT_EQ( n.GetSignedLongLongValue(), static_cast< signed long long >( 42 ) );
}

TEST( CFPP_Number, SetUnsignedCharValue )
{
    CF::Number n;
    
    n.SetUnsignedCharValue( 42 );
    
    ASSERT_EQ( n.GetUnsignedCharValue(), static_cast< unsigned char >( 42 ) );
}

TEST( CFPP_Number, SetUnsignedShortValue )
{
    CF::Number n;
    
    n.SetUnsignedShortValue( 42 );
    
    ASSERT_EQ( n.GetUnsignedShortValue(), static_cast< unsigned short >( 42 ) );
}

TEST( CFPP_Number, SetUnsignedIntValue )
{
    CF::Number n;
    
    n.SetUnsignedIntValue( 42 );
    
    ASSERT_EQ( n.GetUnsignedIntValue(), static_cast< unsigned int >( 42 ) );
}

TEST( CFPP_Number, SetUnsignedLongValue )
{
    CF::Number n;
    
    n.SetUnsignedLongValue( 42 );
    
    ASSERT_EQ( n.GetUnsignedLongValue(), static_cast< unsigned long >( 42 ) );
}

TEST( CFPP_Number, SetUnsignedLongLongValue )
{
	CF::Number n;

	n.SetUnsignedLongLongValue( 42 );

	ASSERT_EQ( n.GetUnsignedLongLongValue(), static_cast< unsigned long long >( 42 ) );
}

TEST( CFPP_Number, SetFloatValue )
{
    CF::Number n;
    
    n.SetFloatValue( 42 );
    
    ASSERT_TRUE( FloatIsEqual( n.GetFloatValue(), 42 ) );
}

TEST( CFPP_Number, SetDoubleValue )
{
    CF::Number n;
    
    n.SetDoubleValue( 42 );
    
    ASSERT_TRUE( FloatIsEqual( n.GetDoubleValue(), 42 ) );
}

TEST( CFPP_Number, Swap )
{
    CF::Number n1( 1 );
    CF::Number n2( 2 );
    
    swap( n1, n2 );
    
    ASSERT_EQ( n1, 2 );
    ASSERT_EQ( n2, 1 );
}

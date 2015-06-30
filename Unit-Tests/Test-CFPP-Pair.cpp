/*******************************************************************************
 * Copyright (c) 2014, Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @file        CFPP-Pair.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    Unit tests for CF::Pair
 */

#include <CF++.h>
#include <GoogleMock/GoogleMock.h>

using namespace testing;

TEST( CFPP_Pair, CTOR_CFType_CFType )
{}

TEST( CFPP_Pair, CTOR_String_CFType )
{}

TEST( CFPP_Pair, CTOR_CChar_CFType )
{}

TEST( CFPP_Pair, CTOR_String_String )
{}

TEST( CFPP_Pair, CTOR_CChar_String )
{}

TEST( CFPP_Pair, CTOR_String_CChar )
{}

TEST( CFPP_Pair, CTOR_CChar_CChar )
{}

TEST( CFPP_Pair, CTOR_String_Number )
{}

TEST( CFPP_Pair, CTOR_CChar_Number )
{}

TEST( CFPP_Pair, CCTOR )
{
    CF::Pair p1( "hello", "world" );
    CF::Pair p2( p1 );
    
    ASSERT_EQ( p1.GetKey(),   p2.GetKey() );
    ASSERT_EQ( p1.GetValue(), p2.GetValue() );
}

TEST( CFPP_Pair, MCTOR )
{
    CF::Pair p1( "hello", "world" );
    CF::Pair p2( std::move( p1 ) );
    
    ASSERT_TRUE(  p1.GetKey()   == NULL );
    ASSERT_TRUE(  p1.GetValue() == NULL );
    ASSERT_FALSE( p2.GetKey()   == NULL );
    ASSERT_FALSE( p2.GetValue() == NULL );
}

TEST( CFPP_Pair, OperatorAssign )
{
    CF::Pair p1( "hello", "world" );
    CF::Pair p2( "hi",    "universe" );
    
    ASSERT_EQ( CF::String( p1.GetKey() ),   "hello" );
    ASSERT_EQ( CF::String( p1.GetValue() ), "world" );
    
    p1 = p2;
    
    ASSERT_EQ( CF::String( p1.GetKey() ),   "hi" );
    ASSERT_EQ( CF::String( p1.GetValue() ), "universe" );
}

TEST( CFPP_Pair, GetKey )
{
    CF::Pair p1( "hello", "world" );
    
    ASSERT_TRUE( p1.GetKey() != NULL );
}

TEST( CFPP_Pair, GetValue )
{
    CF::Pair p1( "hello", "world" );
    
    ASSERT_TRUE( p1.GetValue() != NULL );
}

TEST( CFPP_Pair, SetKey )
{
    CF::Pair p1( "hello", "world" );
    
    p1.SetKey( CF::String( "hi" ) );
    
    ASSERT_EQ( CF::String( p1.GetKey() ), "hi" );
    
    p1.SetKey( NULL );
    
    ASSERT_TRUE( p1.GetKey() == NULL );
}

TEST( CFPP_Pair, SetValue )
{
    CF::Pair p1( "hello", "world" );
    
    p1.SetValue( CF::String( "universe" ) );
    
    ASSERT_EQ( CF::String( p1.GetValue() ), "universe" );
    
    p1.SetValue( NULL );
    
    ASSERT_TRUE( p1.GetValue() == NULL );
}

TEST( CFPP_Pair, Swap )
{
    CF::Pair p1( "hello", "world" );
    CF::Pair p2( "hi",    "universe" );
    
    ASSERT_EQ( CF::String( p1.GetKey() ),   "hello" );
    ASSERT_EQ( CF::String( p1.GetValue() ), "world" );
    ASSERT_EQ( CF::String( p2.GetKey() ),   "hi" );
    ASSERT_EQ( CF::String( p2.GetValue() ), "universe" );
    
    swap( p1, p2 );
    
    ASSERT_EQ( CF::String( p2.GetKey() ),   "hello" );
    ASSERT_EQ( CF::String( p2.GetValue() ), "world" );
    ASSERT_EQ( CF::String( p1.GetKey() ),   "hi" );
    ASSERT_EQ( CF::String( p1.GetValue() ), "universe" );
}

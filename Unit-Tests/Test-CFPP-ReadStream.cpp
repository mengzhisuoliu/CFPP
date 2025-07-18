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
 * @file        Test-CFPP-ReadStream.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    Unit tests for CF::ReadStream
 */

#include <CF++.hpp>
#include <thread>

#define XSTEST_GTEST_COMPAT
#include <XSTest/XSTest.hpp>

TEST( CFPP_ReadStream, CTOR )
{
    CF::ReadStream s;
    
    ASSERT_FALSE( s.IsValid() );
}

TEST( CFPP_ReadStream, CTOR_STDString )
{
    CF::ReadStream s1( std::string( "/etc/hosts" ) );
    CF::ReadStream s2( std::string( "/foo/bar" ) );
    
    ASSERT_TRUE( s1.IsValid() );
    ASSERT_TRUE( s2.IsValid() );
}

TEST( CFPP_ReadStream, CTOR_CChar )
{
    CF::ReadStream s1( "/etc/hosts" );
    CF::ReadStream s2( "/foo/bar" );
    
    ASSERT_TRUE( s1.IsValid() );
    ASSERT_TRUE( s2.IsValid() );
}

TEST( CFPP_ReadStream, CTOR_AutoPointer )
{
    CF::ReadStream s1( CF::AutoPointer( CFReadStreamCreateWithFile( nullptr, CF::URL( "file:///etc/hosts" ) ) ) );
    CF::ReadStream s2( CF::AutoPointer( CFUUIDCreate( nullptr ) ) );
    CF::ReadStream s3( CF::AutoPointer( nullptr ) );
    
    ASSERT_TRUE(  s1.IsValid() );
    ASSERT_FALSE( s2.IsValid() );
    ASSERT_FALSE( s3.IsValid() );
}

TEST( CFPP_ReadStream, CTOR_CFType )
{
    CF::ReadStream s1( CF::URL( "file:///etc/hosts" ) );
    CF::ReadStream s2( static_cast< CFTypeRef >( s1.GetCFObject() ) );
    CF::ReadStream s3( static_cast< CFTypeRef >( nullptr ) );
    
    ASSERT_TRUE(  s1.IsValid() );
    ASSERT_TRUE(  s2.IsValid() );
    ASSERT_FALSE( s3.IsValid() );
}

TEST( CFPP_ReadStream, CTOR_CFReadStream )
{
    CF::ReadStream s1( CF::URL( "file:///etc/hosts" ) );
    CF::ReadStream s2( static_cast< CFReadStreamRef >( const_cast< void * >( s1.GetCFObject() ) ) );
    CF::ReadStream s3( static_cast< CFReadStreamRef >( nullptr ) );
    
    ASSERT_TRUE(  s1.IsValid() );
    ASSERT_TRUE(  s2.IsValid() );
    ASSERT_FALSE( s3.IsValid() );
}

TEST( CFPP_ReadStream, CTOR_NullPointer )
{
    CF::ReadStream s( nullptr );
    
    ASSERT_FALSE( s.IsValid() );
}

TEST( CFPP_ReadStream, CTOR_URL )
{
    CF::ReadStream s1( CF::URL( "file:///etc/hosts" ) );
    CF::ReadStream s2( CF::URL( "file:///foo/bar" ) );
    CF::ReadStream s3( s1 );
    
    ASSERT_TRUE( s1.IsValid() );
    ASSERT_TRUE( s2.IsValid() );
    ASSERT_TRUE( s3.IsValid() );
}

TEST( CFPP_ReadStream, MCTOR )
{
    CF::ReadStream s1( CF::URL( "file:///etc/hosts" ) );
    CF::ReadStream s2( std::move( s1 ) );
    
    ASSERT_FALSE( s1.IsValid() );
    ASSERT_TRUE(  s2.IsValid() );
}

TEST( CFPP_ReadStream, OperatorAssignReadStream )
{
    CF::ReadStream s1( CF::URL( "file:///etc/hosts" ) );
    CF::ReadStream s2;
    CF::ReadStream s3;
    
    ASSERT_TRUE(  s1.IsValid() );
    ASSERT_FALSE( s2.IsValid() );
    ASSERT_FALSE( s3.IsValid() );
    
    s2 = s1;
    
    ASSERT_TRUE( s2.IsValid() );
    
    s2 = s3;
    
    ASSERT_FALSE( s2.IsValid() );
}

TEST( CFPP_ReadStream, OperatorAssignAutoPointer )
{
    CF::ReadStream s1;
    CF::ReadStream s2( "/etc/hosts" );
    CF::ReadStream s3( "/etc/hosts" );
    
    ASSERT_FALSE( s1.IsValid() );
    ASSERT_TRUE(  s2.IsValid() );
    ASSERT_TRUE(  s3.IsValid() );
    
    s1 = CF::AutoPointer( CFReadStreamCreateWithFile( nullptr, CF::URL( "file:///etc/hosts" ) ) );
    s2 = CF::AutoPointer( CFUUIDCreate( nullptr ) );
    s3 = CF::AutoPointer( nullptr );
    
    ASSERT_TRUE(  s1.IsValid() );
    ASSERT_FALSE( s2.IsValid() );
    ASSERT_FALSE( s3.IsValid() );
}

TEST( CFPP_ReadStream, OperatorAssignCFType )
{
    CF::ReadStream s1( CF::URL( "file:///etc/hosts" ) );
    CF::ReadStream s2;
    
    ASSERT_TRUE(  s1.IsValid() );
    ASSERT_FALSE( s2.IsValid() );
    
    s2 = static_cast< CFTypeRef >( s1.GetCFObject() );
    
    ASSERT_TRUE( s2.IsValid() );
    
    s2 = static_cast< CFTypeRef >( nullptr );
    
    ASSERT_FALSE( s2.IsValid() );
}

TEST( CFPP_ReadStream, OperatorAssignCFReadStream )
{
    CF::ReadStream s1( CF::URL( "file:///etc/hosts" ) );
    CF::ReadStream s2;
    
    ASSERT_TRUE(  s1.IsValid() );
    ASSERT_FALSE( s2.IsValid() );
    
    s2 = static_cast< CFReadStreamRef >( const_cast< void * >( s1.GetCFObject() ) );
    
    ASSERT_TRUE( s2.IsValid() );
    
    s2 = static_cast< CFReadStreamRef >( nullptr );
    
    ASSERT_FALSE( s2.IsValid() );
}

TEST( CFPP_ReadStream, OperatorAssignNullPointer )
{
    CF::ReadStream s( std::string( "/etc/hosts" ) );
    
    ASSERT_TRUE( s.IsValid() );
    
    s = nullptr;
    
    ASSERT_FALSE( s.IsValid() );
}

TEST( CFPP_ReadStream, GetTypeID )
{
    CF::ReadStream s;
    
    ASSERT_EQ( s.GetTypeID(), CFReadStreamGetTypeID() );
}

TEST( CFPP_ReadStream, GetCFObject )
{
    CF::ReadStream s1;
    CF::ReadStream s2( CF::URL( "file:///etc/hosts" ) );
    CF::ReadStream s3( static_cast< CFReadStreamRef >( nullptr ) );
    
    ASSERT_TRUE( s1.GetCFObject() == nullptr );
    ASSERT_TRUE( s2.GetCFObject() != nullptr );
    ASSERT_TRUE( s3.GetCFObject() == nullptr );
    ASSERT_EQ( CFGetTypeID( s2.GetCFObject() ), CFReadStreamGetTypeID() );
}

TEST( CFPP_ReadStream, Open )
{
    CF::ReadStream s1;
    CF::ReadStream s2( std::string( "/etc/hosts" ) );
    CF::ReadStream s3( std::string( "/foo/bar" ) );
    
    ASSERT_FALSE( s1.Open() );
    ASSERT_TRUE(  s2.Open() );
    ASSERT_FALSE( s3.Open() );
    
    s1.Close();
    s2.Close();
    s3.Close();
    
    ASSERT_FALSE( s1.Open() );
    ASSERT_FALSE( s2.Open() );
    ASSERT_FALSE( s3.Open() );
    
    s1.Close();
    s2.Close();
    s3.Close();
}

TEST( CFPP_ReadStream, Open_STDString )
{
    CF::ReadStream s;
    
    ASSERT_FALSE( s.IsValid() );
    ASSERT_TRUE(  s.Open( std::string( "/etc/hosts" ) ) );
    ASSERT_TRUE(  s.IsValid() );
    ASSERT_FALSE( s.Open( std::string( "/foo/bar" ) ) );
    ASSERT_TRUE(  s.IsValid() );
    
    s.Close();
}

TEST( CFPP_ReadStream, Open_CChar )
{
    CF::ReadStream s;
    
    ASSERT_FALSE( s.IsValid() );
    ASSERT_TRUE(  s.Open( "/etc/hosts" ) );
    ASSERT_TRUE(  s.IsValid() );
    ASSERT_FALSE( s.Open( "/foo/bar" ) );
    ASSERT_TRUE(  s.IsValid() );
    
    s.Close();
}

TEST( CFPP_ReadStream, Open_URL )
{
    CF::ReadStream s;
    
    ASSERT_FALSE( s.IsValid() );
    ASSERT_TRUE(  s.Open( CF::URL( "file:///etc/hosts" ) ) );
    ASSERT_TRUE(  s.IsValid() );
    ASSERT_FALSE( s.Open( CF::URL( "file:///foo/bar" ) ) );
    ASSERT_TRUE(  s.IsValid() );
    
    s.Close();
}

TEST( CFPP_ReadStream, Close )
{
    CF::ReadStream s1;
    CF::ReadStream s2( "/etc/hosts" );
    CF::ReadStream s3( "/foo/bar" );
    
    s1.Open();
    s2.Open();
    s3.Open();
    
    ASSERT_NO_FATAL_FAILURE( s1.Close() );
    ASSERT_NO_FATAL_FAILURE( s2.Close() );
    ASSERT_NO_FATAL_FAILURE( s3.Close() );
    
    ASSERT_NO_THROW( s1.Close() );
    ASSERT_NO_THROW( s2.Close() );
    ASSERT_NO_THROW( s3.Close() );
}

TEST( CFPP_ReadStream, HasBytesAvailable )
{
    CF::ReadStream s1;
    CF::ReadStream s2( "/etc/hosts" );
    CF::ReadStream s3( "/foo/bar" );
    
    ASSERT_FALSE( s1.HasBytesAvailable() );
    ASSERT_FALSE( s2.HasBytesAvailable() );
    ASSERT_FALSE( s3.HasBytesAvailable() );
    
    s1.Open();
    s2.Open();
    s3.Open();
    
    ASSERT_FALSE( s1.HasBytesAvailable() );
    ASSERT_TRUE(  s2.HasBytesAvailable() );
    ASSERT_FALSE( s3.HasBytesAvailable() );
    
    s1.Close();
    s2.Close();
    s3.Close();
}

TEST( CFPP_ReadStream, GetStatus )
{
    CF::ReadStream s1;
    CF::ReadStream s2( "/etc/hosts" );
    CF::ReadStream s3( "/foo/bar" );
    
    ASSERT_TRUE( s1.GetStatus() == kCFStreamStatusError );
    ASSERT_TRUE( s2.GetStatus() == kCFStreamStatusNotOpen );
    ASSERT_TRUE( s3.GetStatus() == kCFStreamStatusNotOpen );
    
    s1.Open();
    s2.Open();
    s3.Open();
    
    ASSERT_TRUE( s1.GetStatus() == kCFStreamStatusError );
    ASSERT_TRUE( s2.GetStatus() == kCFStreamStatusOpen );
    ASSERT_TRUE( s3.GetStatus() == kCFStreamStatusError );
    
    s1.Close();
    s2.Close();
    s3.Close();
    
    ASSERT_TRUE( s1.GetStatus() == kCFStreamStatusError );
    ASSERT_TRUE( s2.GetStatus() == kCFStreamStatusClosed );
    ASSERT_TRUE( s3.GetStatus() == kCFStreamStatusError );
}

TEST( CFPP_ReadStream, GetError )
{
    CF::ReadStream s1;
    CF::ReadStream s2( "/etc/hosts" );
    CF::ReadStream s3( "/foo/bar" );
    
    ASSERT_EQ( s1.GetError().GetCode(), 0 );
    ASSERT_EQ( s2.GetError().GetCode(), 0 );
    ASSERT_EQ( s3.GetError().GetCode(), 0 );
    
    s1.Open();
    s2.Open();
    s3.Open();
    
    ASSERT_EQ( s1.GetError().GetCode(), 0 );
    ASSERT_EQ( s2.GetError().GetCode(), 0 );
    ASSERT_NE( s3.GetError().GetCode(), 0 );
    
    s1.Close();
    s2.Close();
    s3.Close();
}

TEST( CFPP_ReadStream, Read_BytePtr_CFIndex )
{
    CF::ReadStream s1;
    CF::ReadStream s2( "/etc/hosts" );
    CF::ReadStream s3( "/foo/bar" );
    CF::Data::Byte buf[ 1024 ];
    
    s1.Open();
    s2.Open();
    s3.Open();
    
    ASSERT_NO_FATAL_FAILURE( s1.Read( nullptr, 10 ) );
    ASSERT_NO_FATAL_FAILURE( s2.Read( nullptr, 10 ) );
    ASSERT_NO_FATAL_FAILURE( s3.Read( nullptr, 10 ) );
    
    ASSERT_NO_THROW( s1.Read( nullptr, 10 ) );
    ASSERT_NO_THROW( s2.Read( nullptr, 10 ) );
    ASSERT_NO_THROW( s3.Read( nullptr, 10 ) );
    
    ASSERT_EQ( s1.Read( nullptr, 10 ), -1 );
    ASSERT_EQ( s2.Read( nullptr, 10 ), -1 );
    ASSERT_EQ( s3.Read( nullptr, 10 ), -1 );
    
    ASSERT_EQ( s1.Read( buf, 10 ), -1 );
    ASSERT_GE( s2.Read( buf, 10 ),  0 );
    ASSERT_EQ( s3.Read( buf, 10 ), -1 );
    
    while( s2.HasBytesAvailable() )
    {
        s2.Read( buf, 1024 );
    }
    
    ASSERT_EQ( s2.Read( buf, 10 ), 0 );
    
    s1.Close();
    s2.Close();
    s3.Close();
    
    ASSERT_EQ( s1.Read( buf, 10 ), -1 );
    ASSERT_EQ( s2.Read( buf, 10 ), -1 );
    ASSERT_EQ( s3.Read( buf, 10 ), -1 );
}

TEST( CFPP_ReadStream, Read_CFIndex )
{
    CF::ReadStream s1;
    CF::ReadStream s2( "/etc/hosts" );
    CF::ReadStream s3( "/foo/bar" );
    CF::Data       d1;
    CF::Data       d2;
    CF::Data       d3;
    
    s1.Open();
    s2.Open();
    s3.Open();
    
    d1 = s1.Read( 10 );
    d2 = s2.Read( 10 );
    d3 = s3.Read( 10 );
    
    ASSERT_TRUE( d1.IsValid() );
    ASSERT_TRUE( d2.IsValid() );
    ASSERT_TRUE( d3.IsValid() );
    
    ASSERT_EQ( d1.GetLength(),  0 );
    ASSERT_EQ( d2.GetLength(), 10 );
    ASSERT_EQ( d3.GetLength(),  0 );
    
    d1 = s1.Read();
    d2 = s2.Read();
    d3 = s3.Read();
    
    ASSERT_TRUE( d1.IsValid() );
    ASSERT_TRUE( d2.IsValid() );
    ASSERT_TRUE( d3.IsValid() );
    
    ASSERT_EQ( d1.GetLength(), 0 );
    ASSERT_GT( d2.GetLength(), 0 );
    ASSERT_EQ( d3.GetLength(), 0 );
    
    s1.Close();
    s2.Close();
    s3.Close();
    
    d1 = s1.Read( 10 );
    d2 = s2.Read( 10 );
    d3 = s3.Read( 10 );
    
    ASSERT_TRUE( d1.IsValid() );
    ASSERT_TRUE( d2.IsValid() );
    ASSERT_TRUE( d3.IsValid() );
    
    ASSERT_EQ( d1.GetLength(), 0 );
    ASSERT_EQ( d2.GetLength(), 0 );
    ASSERT_EQ( d3.GetLength(), 0 );
    
    d1 = s1.Read( 10 );
    d2 = s2.Read( 10 );
    d3 = s3.Read( 10 );
    
    ASSERT_TRUE( d1.IsValid() );
    ASSERT_TRUE( d2.IsValid() );
    ASSERT_TRUE( d3.IsValid() );
    
    ASSERT_EQ( d1.GetLength(), 0 );
    ASSERT_EQ( d2.GetLength(), 0 );
    ASSERT_EQ( d3.GetLength(), 0 );
}

TEST( CFPP_ReadStream, GetBuffer )
{
    CF::ReadStream         s1;
    CF::ReadStream         s2( "/etc/hosts" );
    CF::ReadStream         s3( "/foo/bar" );
    CFIndex                i1;
    CFIndex                i2;
    CFIndex                i3;
    const CF::Data::Byte * buf1;
    const CF::Data::Byte * buf2;
    const CF::Data::Byte * buf3;
    
    i1 = 0;
    i2 = 0;
    i3 = 0;
    
    buf1 = s1.GetBuffer( 10, &i1 );
    buf2 = s2.GetBuffer( 10, &i2 );
    buf3 = s3.GetBuffer( 10, &i3 );
    
    ASSERT_TRUE( buf1 == nullptr );
    ASSERT_TRUE( buf2 == nullptr );
    ASSERT_TRUE( buf3 == nullptr );
    
    ASSERT_EQ( i1,  0 );
    ASSERT_EQ( i2, -1 );
    ASSERT_EQ( i3, -1 );
    
    s1.Open();
    s2.Open();
    s3.Open();
    
    buf1 = s1.GetBuffer( 10, &i1 );
    buf2 = s2.GetBuffer( 10, &i2 );
    buf3 = s3.GetBuffer( 10, &i3 );
    
    ASSERT_TRUE( buf1 == nullptr );
    ASSERT_TRUE( buf2 == nullptr );
    ASSERT_TRUE( buf3 == nullptr );
    
    ASSERT_EQ( i1,  0 );
    ASSERT_EQ( i2,  0 );
    ASSERT_EQ( i3, -1 );
    
    s1.Close();
    s2.Close();
    s3.Close();
    
    buf1 = s1.GetBuffer( 10, &i1 );
    buf2 = s2.GetBuffer( 10, &i2 );
    buf3 = s3.GetBuffer( 10, &i3 );
    
    ASSERT_TRUE( buf1 == nullptr );
    ASSERT_TRUE( buf2 == nullptr );
    ASSERT_TRUE( buf3 == nullptr );
    
    ASSERT_EQ( i1,  0 );
    ASSERT_EQ( i2, -1 );
    ASSERT_EQ( i3, -1 );
}

TEST( CFPP_ReadStream, GetProperty )
{
    CF::ReadStream  s1;
    CF::ReadStream  s2( "/etc/hosts" );
    CF::ReadStream  s3( "/foo/bar" );
    CF::AutoPointer p1;
    CF::AutoPointer p2;
    CF::AutoPointer p3;
    
    p1 = s1.GetProperty( kCFStreamPropertyFileCurrentOffset );
    p2 = s2.GetProperty( kCFStreamPropertyFileCurrentOffset );
    p3 = s3.GetProperty( kCFStreamPropertyFileCurrentOffset );
    
    ASSERT_FALSE( p1.IsValid() );
    ASSERT_FALSE( p2.IsValid() );
    ASSERT_FALSE( p3.IsValid() );
    
    s1.Open();
    s2.Open();
    s3.Open();
    
    p1 = s1.GetProperty( kCFStreamPropertyFileCurrentOffset );
    p2 = s2.GetProperty( kCFStreamPropertyFileCurrentOffset );
    p3 = s3.GetProperty( kCFStreamPropertyFileCurrentOffset );
    
    ASSERT_FALSE( p1.IsValid() );
    ASSERT_TRUE(  p2.IsValid() );
    ASSERT_TRUE(  p2.IsNumber() );
    ASSERT_FALSE( p3.IsValid() );
    
    s1.Close();
    s2.Close();
    s3.Close();
}

TEST( CFPP_ReadStream, SetProperty )
{
    CF::ReadStream  s1;
    CF::ReadStream  s2( "/etc/hosts" );
    CF::ReadStream  s3( "/foo/bar" );
    CF::AutoPointer p1;
    CF::AutoPointer p2;
    CF::AutoPointer p3;
    
    p1 = s1.GetProperty( kCFStreamPropertyFileCurrentOffset );
    p2 = s2.GetProperty( kCFStreamPropertyFileCurrentOffset );
    p3 = s3.GetProperty( kCFStreamPropertyFileCurrentOffset );
    
    ASSERT_FALSE( p1.IsValid() );
    ASSERT_FALSE( p2.IsValid() );
    ASSERT_FALSE( p3.IsValid() );
    
    s1.Open();
    s2.Open();
    s3.Open();
    
    ASSERT_FALSE( s1.SetProperty( kCFStreamPropertyFileCurrentOffset, CF::Number( 42 ) ) );
    ASSERT_TRUE(  s2.SetProperty( kCFStreamPropertyFileCurrentOffset, CF::Number( 42 ) ) );
    ASSERT_TRUE(  s3.SetProperty( kCFStreamPropertyFileCurrentOffset, CF::Number( 42 ) ) );
    
    p1 = s1.GetProperty( kCFStreamPropertyFileCurrentOffset );
    p2 = s2.GetProperty( kCFStreamPropertyFileCurrentOffset );
    p3 = s3.GetProperty( kCFStreamPropertyFileCurrentOffset );
    
    ASSERT_FALSE( p1.IsValid() );
    ASSERT_TRUE(  p2.IsValid() );
    ASSERT_TRUE(  p3.IsValid() );
    
    ASSERT_TRUE( p2.IsNumber() );
    ASSERT_TRUE( p3.IsNumber() );
    
    ASSERT_EQ( p2.As< CF::Number >(), 42 );
    ASSERT_EQ( p3.As< CF::Number >(), 42 );
    
    s1.Close();
    s2.Close();
    s3.Close();
}

static bool __client1 = false;
static bool __client2 = false;
static bool __client3 = false;

void __ClientCallback( CFReadStreamRef stream, CFStreamEventType type, void * info );
void __ClientCallback( CFReadStreamRef stream, CFStreamEventType type, void * info )
{
    ( void )stream;
    ( void )type;
    
    if( info != nullptr )
    {
        *( reinterpret_cast< bool * >( info ) ) = true;
    }
}

TEST( CFPP_ReadStream, SetClient )
{
    CF::ReadStream        s1;
    CF::ReadStream        s2( "/etc/hosts" );
    CF::ReadStream        s3( "/foo/bar" );
    CFStreamClientContext ctx1;
    CFStreamClientContext ctx2;
    CFStreamClientContext ctx3;
    
    memset( &ctx1, 0, sizeof( CFStreamClientContext ) );
    memset( &ctx2, 0, sizeof( CFStreamClientContext ) );
    memset( &ctx3, 0, sizeof( CFStreamClientContext ) );
    
    ctx1.info = &__client1;
    ctx2.info = &__client2;
    ctx3.info = &__client3;
    
    ASSERT_FALSE( s1.SetClient( kCFStreamEventOpenCompleted, __ClientCallback, &ctx1 ) );
    ASSERT_TRUE(  s2.SetClient( kCFStreamEventOpenCompleted, __ClientCallback, &ctx2 ) );
    ASSERT_TRUE(  s3.SetClient( kCFStreamEventOpenCompleted, __ClientCallback, &ctx3 ) );
    
    s1.ScheduleWithRunLoop( CFRunLoopGetCurrent(), kCFRunLoopDefaultMode );
    s2.ScheduleWithRunLoop( CFRunLoopGetCurrent(), kCFRunLoopDefaultMode );
    s3.ScheduleWithRunLoop( CFRunLoopGetCurrent(), kCFRunLoopDefaultMode );
    
    {
        CFRunLoopRef rl;
        
        rl = CFRunLoopGetCurrent();
        
        std::thread t
        (
            [ s1, s2, s3, rl ] () mutable
            {
                std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );
                
                s1.Open();
                s2.Open();
                s3.Open();
                
                std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );
                
                CFRunLoopStop( rl );
            }
        );
        
        t.detach();
    }
    
    CFRunLoopRun();
    
    ASSERT_FALSE( __client1 );
    ASSERT_TRUE(  __client2 );
    ASSERT_FALSE( __client3 );
    
    s1.UnscheduleFromRunLoop( CFRunLoopGetCurrent(), kCFRunLoopDefaultMode );
    s2.UnscheduleFromRunLoop( CFRunLoopGetCurrent(), kCFRunLoopDefaultMode );
    s3.UnscheduleFromRunLoop( CFRunLoopGetCurrent(), kCFRunLoopDefaultMode );
    
    s1.Close();
    s2.Close();
    s3.Close();
}

TEST( CFPP_ReadStream, Swap )
{
    CF::ReadStream s1( "/etc/hosts" );
    CF::ReadStream s2( "/foo/bar" );
    
    s1.Open();
    s2.Open();
    
    ASSERT_TRUE( s1.GetStatus() == kCFStreamStatusOpen );
    ASSERT_TRUE( s2.GetStatus() == kCFStreamStatusError );
    
    swap( s1, s2 );
    
    ASSERT_TRUE( s1.GetStatus() == kCFStreamStatusError );
    ASSERT_TRUE( s2.GetStatus() == kCFStreamStatusOpen );
    
    s1.Close();
    s2.Close();
}

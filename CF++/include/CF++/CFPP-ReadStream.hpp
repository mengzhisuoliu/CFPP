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
 * @header      CFPP-ReadStream.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFReadStreamRef wrapper
 */

#ifndef CFPP_READ_STREAM_HPP
#define CFPP_READ_STREAM_HPP

namespace CF
{
    class CFPP_EXPORT ReadStream: public Type
    {
        public:
            
            ReadStream();
            ReadStream( const std::string & path );
            ReadStream( const char * path );
            ReadStream( URL url );
            ReadStream( const ReadStream & value );
            ReadStream( const AutoPointer & value );
            ReadStream( CFTypeRef value );
            ReadStream( CFReadStreamRef value );
            ReadStream( std::nullptr_t );
            ReadStream( ReadStream && value ) noexcept;
            
            ~ReadStream() override;
            
            ReadStream & operator =( ReadStream value );
            ReadStream & operator =( const AutoPointer & value );
            ReadStream & operator =( CFTypeRef value );
            ReadStream & operator =( CFReadStreamRef value );
            ReadStream & operator =( std::nullptr_t );
            
            CFTypeID  GetTypeID()   const override;
            CFTypeRef GetCFObject() const override;
            
            bool Open();
            bool Open( const std::string & path );
            bool Open( const char * path );
            bool Open( const URL & url );
            void Close();
            
            bool           HasBytesAvailable()                const;
            CFStreamStatus GetStatus()                        const;
            Error          GetError()                         const;
            AutoPointer    GetProperty( const String & name ) const;
            
            CFIndex            Read( Data::Byte * buffer, CFIndex length );
            Data               Read( CFIndex length = 0 );
            const Data::Byte * GetBuffer( CFIndex maxBytesToRead, CFIndex * numBytesRead );
            bool               SetProperty( const String & name, CFTypeRef value );
            bool               SetClient( CFOptionFlags events, CFReadStreamClientCallBack callback, CFStreamClientContext * context );
            void               ScheduleWithRunLoop( CFRunLoopRef runLoop, CF::String mode );
            void               UnscheduleFromRunLoop( CFRunLoopRef runLoop, CF::String mode );
            
            friend void swap( ReadStream & v1, ReadStream & v2 ) noexcept;
            
            #ifdef __clang__
            #pragma clang diagnostic push
            #pragma clang diagnostic ignored "-Wpadded"
            #endif
            
            #if __cplusplus >= 201703L
            class CFPP_EXPORT Iterator
            #else
            class CFPP_EXPORT Iterator: public std::iterator< std::forward_iterator_tag, Data >
            #endif
            {
                public:
                
                    #if __cplusplus >= 201703L
                    using iterator_category = std::bidirectional_iterator_tag;
                    using value_type        = Data;
                    using difference_type   = ptrdiff_t;
                    using pointer           = Data *;
                    using reference         = Data &;
                    #endif
                    
                    Iterator();
                    Iterator( const Iterator & value );
                    Iterator( Iterator && value ) noexcept;
                    
                    virtual ~Iterator();
                    
                    Iterator & operator =( Iterator value );
                    Iterator & operator ++();
                    Iterator   operator ++( int );
                    
                    Iterator & operator += ( CFIndex value );
                    
                    Iterator operator +( CFIndex value );
                    
                    bool operator == ( const Iterator & value ) const;
                    bool operator != ( const Iterator & value ) const;
                    
                    Data operator *();
                    
                    operator Data ();
                    
                    friend void swap( Iterator & v1, Iterator & v2 ) noexcept;
                    
                private:
                    
                    friend class ReadStream;
                    
                    Iterator( CFReadStreamRef stream, CFIndex bytesToRead, bool end );
                    
                    void _Read();
                    
                    CFReadStreamRef _cfObject;
                    CFIndex         _bytesToRead;
                    CFIndex         _i;
                    Data            _data;
                    bool            _end;
            };
            
            #ifdef __clang__
            #pragma clang diagnostic pop
            #endif
            
            Iterator begin( CFIndex bytesToRead = 0 ) const;
            Iterator end()                            const;
            
        private:
            
            CFReadStreamRef _cfObject;
    };
}

#endif /* CFPP_READ_STREAM_HPP */

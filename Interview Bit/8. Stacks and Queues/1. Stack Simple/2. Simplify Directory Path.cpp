/ /   G i v e n   a   s t r i n g   A   r e p r e s e n t i n g   a n   a b s o l u t e   p a t h   f o r   a   f i l e   ( U n i x - s t y l e ) .  
 / /   R e t u r n   t h e   s t r i n g   A   a f t e r   s i m p l i f y i n g   t h e   a b s o l u t e   p a t h .  
 / /   N o t e :  
 / /   A b s o l u t e   p a t h   a l w a y s   b e g i n   w i t h    /    (   r o o t   d i r e c t o r y   ) .  
 / /   P a t h   w i l l   n o t   h a v e   w h i t e s p a c e   c h a r a c t e r s .  
  
 / /   I n p u t   1 :  
 / /           A   =   " / h o m e / "  
 / /   O u t p u t   1 :  
 / /           " / h o m e "  
  
 / /   I n p u t   2 :  
 / /           A   =   " / a / . / b / . . / . . / c / "  
 / /   O u t p u t   2 :  
 / /           " / c "  
  
  
 / / S o l u t i o n   A p p r o a c h   : -  
 M o r e   o f   a   s i m u l a t i o n   p r o b l e m .  
 B r e a k   t h e   s t r i n g   a l o n g    /    a n d   p r o c e s s   t h e   s u b s t r i n g s   i n   o r d e r   o n e   b y   o n e .    . .    i n d i c a t e s   p o p p i n g   a n   e n t r y   u n l e s s   t h e r e   i s   n o t h i n g   t o   p o p .  
  
  
 / / F i r s t   S o l u t i o n   : -  
 s t r i n g   S o l u t i o n : : s i m p l i f y P a t h ( s t r i n g   s t r )   {  
         v e c t o r < s t r i n g > v ;  
         s t r i n g   a n s = " " ;  
         f o r ( i n t   i = 0 ; i < s t r . l e n g t h ( ) ; i + + ) {  
                 s t r i n g   p a t h = " " ;  
                 w h i l e ( i < s t r . l e n g t h ( )   a n d   s t r [ i ] ! = ' / ' ) {  
                         p a t h + = s t r [ i ] ;  
                         i + + ;  
                 }  
  
                 i f ( p a t h = = " "   o r   p a t h = = " . " )    
                         c o n t i n u e ;  
                 e l s e   i f ( p a t h = = " . . " ) {  
                         i f ( v . s i z e ( ) > 0 )   {  
                                 v . p o p _ b a c k ( ) ;  
                         }  
                 }  
                 e l s e {  
                         v . p u s h _ b a c k ( p a t h ) ;  
                 }    
         }  
         i f ( v . s i z e ( ) = = 0 ) {  
                 r e t u r n   " / " ;  
         }  
  
         f o r ( i n t   i = 0 ; i < v . s i z e ( ) ; i + + ) {  
                 a n s + = " / " + v [ i ] ;  
         }  
         r e t u r n   a n s ;  
 }  
  
 / / S e c o n d   S o l u t i o n   : -  
 s t r i n g   S o l u t i o n : : s i m p l i f y P a t h ( s t r i n g   p a t h )   {  
 	 s t r i n g   r e s ,   t m p ;  
 	 v e c t o r   s t k ;  
 	 s t r i n g s t r e a m   s s ( p a t h ) ;  
 	 w h i l e ( g e t l i n e ( s s , t m p , ' / ' ) )   {  
 	 	 i f   ( t m p   = =   " "   o r   t m p   = =   " . " )   c o n t i n u e ;  
 	 	 i f   ( t m p   = =   " . . "   a n d   ! s t k . e m p t y ( ) )   s t k . p o p _ b a c k ( ) ;  
 	 	 e l s e   i f   ( t m p   ! =   " . . " )   s t k . p u s h _ b a c k ( t m p ) ;  
 	 }  
 	 f o r ( a u t o   s t r   :   s t k )   r e s   + =   " / " + s t r ;  
 	 r e t u r n   r e s . e m p t y ( )   ?   " / "   :   r e s ;  
 }  
  
  
 / / T h i r d   S o l u t i o n   : - U s i n g - S t a c k - A n d - S t r t o k - S t r  
 s t r i n g   S o l u t i o n : : s i m p l i f y P a t h ( s t r i n g   A )   {  
 	 v e c t o r < s t r i n g > v ;  
  
 	 c h a r   t e m p   =   s t r t o k ( ( c h a r ) A . c _ s t r ( ) , " / " ) ;  
 	 w h i l e ( t e m p ! = N U L L ) {  
 	 	 v . p u s h _ b a c k ( t e m p ) ;  
 	 	 t e m p   =   s t r t o k ( N U L L , " / " ) ;  
 	 }  
  
 	 i n t   i   =   0 ;  
 	 s t a c k < s t r i n g > s t ;  
  
 	 w h i l e ( i < v . s i z e ( ) ) {  
 	 	 i f ( v [ i ] ! = " . . " & & v [ i ] ! = " . " )  
 	 	 	 s t . p u s h ( v [ i ] ) ;  
 	 	 e l s e {  
 	 	 	 i f ( ! s t . e m p t y ( ) & & v [ i ] = = " . . " )  
 	 	 	 	 s t . p o p ( ) ;  
 	 	 }  
 	 	 i + + ;  
 	 }  
 	 v . c l e a r ( ) ;  
  
 	 w h i l e ( ! s t . e m p t y ( ) ) {  
 	 	 v . p u s h _ b a c k ( s t . t o p ( ) ) ;  
 	 	 s t . p o p ( ) ;  
 	 }  
  
 	 r e v e r s e ( v . b e g i n ( ) , v . e n d ( ) ) ;  
 	  
 	 s t r i n g   s   =   " / " ;  
 	 i f ( v . s i z e ( ) > 0 )  
 	 	 s + = v [ 0 ] ;  
  
 	 f o r ( i n t   i = 1 ; i < v . s i z e ( ) ; i + + ) {  
 	 	 s + = " / " + v [ i ] ;  
 	 }  
  
 	 r e t u r n   s ;  
 }  
 
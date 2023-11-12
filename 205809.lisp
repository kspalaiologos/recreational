(defmacro f(x)(match x((a b c)(S a b c)[(tie a c b c)/ 2])((a b)(K a b)a)(a(I a)a)((a b)(a b)(tie(f a)(f b)))(x)))(def g $(iterate /= f))

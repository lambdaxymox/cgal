
/*!
\ingroup PkgKernelDKernelConcept
\cgalConcept

A model for this must provide: 

*/

class Kernel_d::Linear_rank_d {
public:

/*! 
computes 
the linear rank of the vectors in `A = tuple [first,last)`. 
\pre \f$ A\f$ contains vectors of the same dimension \f$ d\f$. 

\cgalRequires The value type of `ForwardIterator` is `Kernel_d::Vector_d`. 
*/ 
template <class ForwardIterator> int 
operator()(ForwardIterator first, ForwardIterator last); 

}; /* end Kernel_d::Linear_rank_d */


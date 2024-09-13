<TeXmacs|2.1.1>

<style|generic>

<\body>
  <section*|Indexing for <verbatim|grid/multigrid.h>>

  Given <math|l> the grid level, the number of grid points along one
  dimension is

  <\equation*>
    s<around*|(|l|)>=2<rsup|l>+2*g
  </equation*>

  with <math|g> the number of ghost layers (usually 2).

  If we choose to pack elements row-by-row (i.e. elements are closest along
  rows), the index of field <math|a> at coordinates <math|<around*|(|i,j|)>>
  is given by

  <\equation*>
    j+i*s<around*|(|l|)>+a*s<around*|(|l|)><rsup|2>
  </equation*>

  In a similar fashion, if we pack row-by-row and level-by-level, the index
  of field <math|a> at coordinates <math|<around*|(|i,j|)>> and level
  <math|l> is given by

  <\equation*>
    j+i*s<around*|(|l|)>+l*<big|sum><rsup|k\<less\>l><rsub|k=0>s<around*|(|k|)><rsup|2>+a*<big|sum><rsup|k\<less\>depth+1><rsub|k=0>s<around*|(|k|)><rsup|2>
  </equation*>

  We can further develop

  <\equation*>
    <big|sum><rsup|k\<less\>l><rsub|k=0>s<around*|(|k|)><rsup|2>=<big|sum><rsup|k\<less\>l><rsub|k=0><around*|(|2<rsup|k>+2*g|)><rsup|2>
  </equation*>

  <\eqnarray*>
    <tformat|<table|<row|<cell|<big|sum><rsup|k\<less\>l><rsub|k=0>s<around*|(|k|)><rsup|2>>|<cell|=>|<cell|<big|sum><rsup|k\<less\>l><rsub|k=0><around*|(|2<rsup|k>+2*g|)><rsup|2>>>|<row|<cell|>|<cell|=>|<cell|<big|sum><rsup|k\<less\>l><rsub|k=0>4<rsup|*k>+4*g*2<rsup|k>+4*g<rsup|2>>>|<row|<cell|>|<cell|=>|<cell|<frac|4<rsup|l>-1|3>+4*g*<around*|(|2<rsup|l>-1+g*l|)>>>>>
  </eqnarray*>
</body>

<\initial>
  <\collection>
    <associate|page-height|auto>
    <associate|page-type|letter>
    <associate|page-width|auto>
  </collection>
</initial>

<\references>
  <\collection>
    <associate|auto-1|<tuple|?|?>>
  </collection>
</references>

<\auxiliary>
  <\collection>
    <\associate|toc>
      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|Indexing
      for <with|font-family|<quote|tt>|language|<quote|verbatim>|grid/multigrid.h>>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-1><vspace|0.5fn>
    </associate>
  </collection>
</auxiliary>
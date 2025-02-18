#if dimension == 1
postmacro foreach_neighbor (int _s = GHOSTS,
			    Point _p = point, break = (_k = _nn + 1)) {
  {
    const int _nn = _s;
    const int _i = _p.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      _p.i = _i + _k;
      POINT_VARIABLES (_p);
      {...}
    }
    _p.i = _i;
  }
}
#elif dimension == 2
postmacro foreach_neighbor (int _s = GHOSTS,
			    Point _p = point, break = (_k = _l = _nn + 1)) {
  {
    const int _nn = _s;
    const int _i = _p.i, _j = _p.j;
    for (int _k = - _nn; _k <= _nn; _k++) {
      _p.i = _i + _k;
      for (int _l = - _nn; _l <= _nn; _l++) {
	_p.j = _j + _l;
	POINT_VARIABLES (_p);
	{...}
      }
    }
    _p.i = _i; _p.j = _j;
  }
}
#else // dimension == 3
postmacro foreach_neighbor (int _s = GHOSTS,
			    Point _p = point, break = (_l = _m = _n = _nn + 1)) {
  {
    const int _nn = _s;
    const int _i = _p.i, _j = _p.j, _k = _p.k;
    for (int _l = - _nn; _l <= _nn; _l++) {
      _p.i = _i + _l;
      for (int _m = - _nn; _m <= _nn; _m++) {
	_p.j = _j + _m;
	for (int _n = - _nn; _n <= _nn; _n++) {
	  _p.k = _k + _n;
	  POINT_VARIABLES (_p);
	  {...}
	}
      }
    }
    _p.i = _i; _p.j = _j; _p.k = _k;
  }
}
#endif // dimension == 3

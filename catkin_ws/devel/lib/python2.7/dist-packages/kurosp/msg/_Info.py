"""autogenerated by genpy from kurosp/Info.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class Info(genpy.Message):
  _md5sum = "e7be2d7c158064f808f034be3a19e5b8"
  _type = "kurosp/Info"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """uint8 response_mode #= 3 # KUKA_RMODE_STREAM
uint32 response_ms #= 20 # [ms]
uint32 traj_id #= 666 # a trajectory id
bool run #= 1 # YES
uint32 vel #= 200 # [mm/s]
uint32 tol #= 20 # [mm]
uint8 frame_type #= 1 # KUKA_CARTESIAN

"""
  __slots__ = ['response_mode','response_ms','traj_id','run','vel','tol','frame_type']
  _slot_types = ['uint8','uint32','uint32','bool','uint32','uint32','uint8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       response_mode,response_ms,traj_id,run,vel,tol,frame_type

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Info, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.response_mode is None:
        self.response_mode = 0
      if self.response_ms is None:
        self.response_ms = 0
      if self.traj_id is None:
        self.traj_id = 0
      if self.run is None:
        self.run = False
      if self.vel is None:
        self.vel = 0
      if self.tol is None:
        self.tol = 0
      if self.frame_type is None:
        self.frame_type = 0
    else:
      self.response_mode = 0
      self.response_ms = 0
      self.traj_id = 0
      self.run = False
      self.vel = 0
      self.tol = 0
      self.frame_type = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_B2IB2IB.pack(_x.response_mode, _x.response_ms, _x.traj_id, _x.run, _x.vel, _x.tol, _x.frame_type))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 19
      (_x.response_mode, _x.response_ms, _x.traj_id, _x.run, _x.vel, _x.tol, _x.frame_type,) = _struct_B2IB2IB.unpack(str[start:end])
      self.run = bool(self.run)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_B2IB2IB.pack(_x.response_mode, _x.response_ms, _x.traj_id, _x.run, _x.vel, _x.tol, _x.frame_type))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 19
      (_x.response_mode, _x.response_ms, _x.traj_id, _x.run, _x.vel, _x.tol, _x.frame_type,) = _struct_B2IB2IB.unpack(str[start:end])
      self.run = bool(self.run)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_B2IB2IB = struct.Struct("<B2IB2IB")
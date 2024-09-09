import omni.ui as ui
from r_o_b_o_t_o.cef import CppWidget

my_window = ui.Window("Chromium Window", width=300, height=300, padding_x=0, padding_y=0)
with my_window.frame:
	CppWidget()

/* auto-generated */
#if defined(REQ_VTW1)
#if defined(VTW_SIZE) && VTW_SIZE == 1
#warning "using VTW1 with 1"
#define VTW1(v,x) {TW_CEXP, v+0, x} 
#endif // VTW_SIZE == 1
#if defined(VTW_SIZE) && VTW_SIZE == 2
#warning "using VTW1 with 2"
#define VTW1(v,x) {TW_CEXP, v+0, x}, {TW_CEXP, v+1, x} 
#endif // VTW_SIZE == 2
#if defined(VTW_SIZE) && VTW_SIZE == 4
#warning "using VTW1 with 4"
#define VTW1(v,x) {TW_CEXP, v+0, x}, {TW_CEXP, v+1, x}, {TW_CEXP, v+2, x}, {TW_CEXP, v+3, x} 
#endif // VTW_SIZE == 4
#if defined(VTW_SIZE) && VTW_SIZE == 8
#warning "using VTW1 with 8"
#define VTW1(v,x) {TW_CEXP, v+0, x}, {TW_CEXP, v+1, x}, {TW_CEXP, v+2, x}, {TW_CEXP, v+3, x}, \
	{TW_CEXP, v+4, x}, {TW_CEXP, v+5, x}, {TW_CEXP, v+6, x}, {TW_CEXP, v+7, x} 
#endif // VTW_SIZE == 8
#if defined(VTW_SIZE) && VTW_SIZE == 16
#warning "using VTW1 with 16"
#define VTW1(v,x) {TW_CEXP, v+0, x}, {TW_CEXP, v+1, x}, {TW_CEXP, v+2, x}, {TW_CEXP, v+3, x}, \
	{TW_CEXP, v+4, x}, {TW_CEXP, v+5, x}, {TW_CEXP, v+6, x}, {TW_CEXP, v+7, x}, \
	{TW_CEXP, v+8, x}, {TW_CEXP, v+9, x}, {TW_CEXP, v+10, x}, {TW_CEXP, v+11, x}, \
	{TW_CEXP, v+12, x}, {TW_CEXP, v+13, x}, {TW_CEXP, v+14, x}, {TW_CEXP, v+15, x} 
#endif // VTW_SIZE == 16
#if defined(VTW_SIZE) && VTW_SIZE == 32
#warning "using VTW1 with 32"
#define VTW1(v,x) {TW_CEXP, v+0, x}, {TW_CEXP, v+1, x}, {TW_CEXP, v+2, x}, {TW_CEXP, v+3, x}, \
	{TW_CEXP, v+4, x}, {TW_CEXP, v+5, x}, {TW_CEXP, v+6, x}, {TW_CEXP, v+7, x}, \
	{TW_CEXP, v+8, x}, {TW_CEXP, v+9, x}, {TW_CEXP, v+10, x}, {TW_CEXP, v+11, x}, \
	{TW_CEXP, v+12, x}, {TW_CEXP, v+13, x}, {TW_CEXP, v+14, x}, {TW_CEXP, v+15, x}, \
	{TW_CEXP, v+16, x}, {TW_CEXP, v+17, x}, {TW_CEXP, v+18, x}, {TW_CEXP, v+19, x}, \
	{TW_CEXP, v+20, x}, {TW_CEXP, v+21, x}, {TW_CEXP, v+22, x}, {TW_CEXP, v+23, x}, \
	{TW_CEXP, v+24, x}, {TW_CEXP, v+25, x}, {TW_CEXP, v+26, x}, {TW_CEXP, v+27, x}, \
	{TW_CEXP, v+28, x}, {TW_CEXP, v+29, x}, {TW_CEXP, v+30, x}, {TW_CEXP, v+31, x} 
#endif // VTW_SIZE == 32
#if defined(VTW_SIZE) && VTW_SIZE == 64
#warning "using VTW1 with 64"
#define VTW1(v,x) {TW_CEXP, v+0, x}, {TW_CEXP, v+1, x}, {TW_CEXP, v+2, x}, {TW_CEXP, v+3, x}, \
	{TW_CEXP, v+4, x}, {TW_CEXP, v+5, x}, {TW_CEXP, v+6, x}, {TW_CEXP, v+7, x}, \
	{TW_CEXP, v+8, x}, {TW_CEXP, v+9, x}, {TW_CEXP, v+10, x}, {TW_CEXP, v+11, x}, \
	{TW_CEXP, v+12, x}, {TW_CEXP, v+13, x}, {TW_CEXP, v+14, x}, {TW_CEXP, v+15, x}, \
	{TW_CEXP, v+16, x}, {TW_CEXP, v+17, x}, {TW_CEXP, v+18, x}, {TW_CEXP, v+19, x}, \
	{TW_CEXP, v+20, x}, {TW_CEXP, v+21, x}, {TW_CEXP, v+22, x}, {TW_CEXP, v+23, x}, \
	{TW_CEXP, v+24, x}, {TW_CEXP, v+25, x}, {TW_CEXP, v+26, x}, {TW_CEXP, v+27, x}, \
	{TW_CEXP, v+28, x}, {TW_CEXP, v+29, x}, {TW_CEXP, v+30, x}, {TW_CEXP, v+31, x}, \
	{TW_CEXP, v+32, x}, {TW_CEXP, v+33, x}, {TW_CEXP, v+34, x}, {TW_CEXP, v+35, x}, \
	{TW_CEXP, v+36, x}, {TW_CEXP, v+37, x}, {TW_CEXP, v+38, x}, {TW_CEXP, v+39, x}, \
	{TW_CEXP, v+40, x}, {TW_CEXP, v+41, x}, {TW_CEXP, v+42, x}, {TW_CEXP, v+43, x}, \
	{TW_CEXP, v+44, x}, {TW_CEXP, v+45, x}, {TW_CEXP, v+46, x}, {TW_CEXP, v+47, x}, \
	{TW_CEXP, v+48, x}, {TW_CEXP, v+49, x}, {TW_CEXP, v+50, x}, {TW_CEXP, v+51, x}, \
	{TW_CEXP, v+52, x}, {TW_CEXP, v+53, x}, {TW_CEXP, v+54, x}, {TW_CEXP, v+55, x}, \
	{TW_CEXP, v+56, x}, {TW_CEXP, v+57, x}, {TW_CEXP, v+58, x}, {TW_CEXP, v+59, x}, \
	{TW_CEXP, v+60, x}, {TW_CEXP, v+61, x}, {TW_CEXP, v+62, x}, {TW_CEXP, v+63, x} 
#endif // VTW_SIZE == 64
#if defined(VTW_SIZE) && VTW_SIZE == 128
#warning "using VTW1 with 128"
#define VTW1(v,x) {TW_CEXP, v+0, x}, {TW_CEXP, v+1, x}, {TW_CEXP, v+2, x}, {TW_CEXP, v+3, x}, \
	{TW_CEXP, v+4, x}, {TW_CEXP, v+5, x}, {TW_CEXP, v+6, x}, {TW_CEXP, v+7, x}, \
	{TW_CEXP, v+8, x}, {TW_CEXP, v+9, x}, {TW_CEXP, v+10, x}, {TW_CEXP, v+11, x}, \
	{TW_CEXP, v+12, x}, {TW_CEXP, v+13, x}, {TW_CEXP, v+14, x}, {TW_CEXP, v+15, x}, \
	{TW_CEXP, v+16, x}, {TW_CEXP, v+17, x}, {TW_CEXP, v+18, x}, {TW_CEXP, v+19, x}, \
	{TW_CEXP, v+20, x}, {TW_CEXP, v+21, x}, {TW_CEXP, v+22, x}, {TW_CEXP, v+23, x}, \
	{TW_CEXP, v+24, x}, {TW_CEXP, v+25, x}, {TW_CEXP, v+26, x}, {TW_CEXP, v+27, x}, \
	{TW_CEXP, v+28, x}, {TW_CEXP, v+29, x}, {TW_CEXP, v+30, x}, {TW_CEXP, v+31, x}, \
	{TW_CEXP, v+32, x}, {TW_CEXP, v+33, x}, {TW_CEXP, v+34, x}, {TW_CEXP, v+35, x}, \
	{TW_CEXP, v+36, x}, {TW_CEXP, v+37, x}, {TW_CEXP, v+38, x}, {TW_CEXP, v+39, x}, \
	{TW_CEXP, v+40, x}, {TW_CEXP, v+41, x}, {TW_CEXP, v+42, x}, {TW_CEXP, v+43, x}, \
	{TW_CEXP, v+44, x}, {TW_CEXP, v+45, x}, {TW_CEXP, v+46, x}, {TW_CEXP, v+47, x}, \
	{TW_CEXP, v+48, x}, {TW_CEXP, v+49, x}, {TW_CEXP, v+50, x}, {TW_CEXP, v+51, x}, \
	{TW_CEXP, v+52, x}, {TW_CEXP, v+53, x}, {TW_CEXP, v+54, x}, {TW_CEXP, v+55, x}, \
	{TW_CEXP, v+56, x}, {TW_CEXP, v+57, x}, {TW_CEXP, v+58, x}, {TW_CEXP, v+59, x}, \
	{TW_CEXP, v+60, x}, {TW_CEXP, v+61, x}, {TW_CEXP, v+62, x}, {TW_CEXP, v+63, x}, \
	{TW_CEXP, v+64, x}, {TW_CEXP, v+65, x}, {TW_CEXP, v+66, x}, {TW_CEXP, v+67, x}, \
	{TW_CEXP, v+68, x}, {TW_CEXP, v+69, x}, {TW_CEXP, v+70, x}, {TW_CEXP, v+71, x}, \
	{TW_CEXP, v+72, x}, {TW_CEXP, v+73, x}, {TW_CEXP, v+74, x}, {TW_CEXP, v+75, x}, \
	{TW_CEXP, v+76, x}, {TW_CEXP, v+77, x}, {TW_CEXP, v+78, x}, {TW_CEXP, v+79, x}, \
	{TW_CEXP, v+80, x}, {TW_CEXP, v+81, x}, {TW_CEXP, v+82, x}, {TW_CEXP, v+83, x}, \
	{TW_CEXP, v+84, x}, {TW_CEXP, v+85, x}, {TW_CEXP, v+86, x}, {TW_CEXP, v+87, x}, \
	{TW_CEXP, v+88, x}, {TW_CEXP, v+89, x}, {TW_CEXP, v+90, x}, {TW_CEXP, v+91, x}, \
	{TW_CEXP, v+92, x}, {TW_CEXP, v+93, x}, {TW_CEXP, v+94, x}, {TW_CEXP, v+95, x}, \
	{TW_CEXP, v+96, x}, {TW_CEXP, v+97, x}, {TW_CEXP, v+98, x}, {TW_CEXP, v+99, x}, \
	{TW_CEXP, v+100, x}, {TW_CEXP, v+101, x}, {TW_CEXP, v+102, x}, {TW_CEXP, v+103, x}, \
	{TW_CEXP, v+104, x}, {TW_CEXP, v+105, x}, {TW_CEXP, v+106, x}, {TW_CEXP, v+107, x}, \
	{TW_CEXP, v+108, x}, {TW_CEXP, v+109, x}, {TW_CEXP, v+110, x}, {TW_CEXP, v+111, x}, \
	{TW_CEXP, v+112, x}, {TW_CEXP, v+113, x}, {TW_CEXP, v+114, x}, {TW_CEXP, v+115, x}, \
	{TW_CEXP, v+116, x}, {TW_CEXP, v+117, x}, {TW_CEXP, v+118, x}, {TW_CEXP, v+119, x}, \
	{TW_CEXP, v+120, x}, {TW_CEXP, v+121, x}, {TW_CEXP, v+122, x}, {TW_CEXP, v+123, x}, \
	{TW_CEXP, v+124, x}, {TW_CEXP, v+125, x}, {TW_CEXP, v+126, x}, {TW_CEXP, v+127, x} 
#endif // VTW_SIZE == 128
#if defined(VTW_SIZE) && VTW_SIZE == 256
#warning "using VTW1 with 256"
#define VTW1(v,x) {TW_CEXP, v+0, x}, {TW_CEXP, v+1, x}, {TW_CEXP, v+2, x}, {TW_CEXP, v+3, x}, \
	{TW_CEXP, v+4, x}, {TW_CEXP, v+5, x}, {TW_CEXP, v+6, x}, {TW_CEXP, v+7, x}, \
	{TW_CEXP, v+8, x}, {TW_CEXP, v+9, x}, {TW_CEXP, v+10, x}, {TW_CEXP, v+11, x}, \
	{TW_CEXP, v+12, x}, {TW_CEXP, v+13, x}, {TW_CEXP, v+14, x}, {TW_CEXP, v+15, x}, \
	{TW_CEXP, v+16, x}, {TW_CEXP, v+17, x}, {TW_CEXP, v+18, x}, {TW_CEXP, v+19, x}, \
	{TW_CEXP, v+20, x}, {TW_CEXP, v+21, x}, {TW_CEXP, v+22, x}, {TW_CEXP, v+23, x}, \
	{TW_CEXP, v+24, x}, {TW_CEXP, v+25, x}, {TW_CEXP, v+26, x}, {TW_CEXP, v+27, x}, \
	{TW_CEXP, v+28, x}, {TW_CEXP, v+29, x}, {TW_CEXP, v+30, x}, {TW_CEXP, v+31, x}, \
	{TW_CEXP, v+32, x}, {TW_CEXP, v+33, x}, {TW_CEXP, v+34, x}, {TW_CEXP, v+35, x}, \
	{TW_CEXP, v+36, x}, {TW_CEXP, v+37, x}, {TW_CEXP, v+38, x}, {TW_CEXP, v+39, x}, \
	{TW_CEXP, v+40, x}, {TW_CEXP, v+41, x}, {TW_CEXP, v+42, x}, {TW_CEXP, v+43, x}, \
	{TW_CEXP, v+44, x}, {TW_CEXP, v+45, x}, {TW_CEXP, v+46, x}, {TW_CEXP, v+47, x}, \
	{TW_CEXP, v+48, x}, {TW_CEXP, v+49, x}, {TW_CEXP, v+50, x}, {TW_CEXP, v+51, x}, \
	{TW_CEXP, v+52, x}, {TW_CEXP, v+53, x}, {TW_CEXP, v+54, x}, {TW_CEXP, v+55, x}, \
	{TW_CEXP, v+56, x}, {TW_CEXP, v+57, x}, {TW_CEXP, v+58, x}, {TW_CEXP, v+59, x}, \
	{TW_CEXP, v+60, x}, {TW_CEXP, v+61, x}, {TW_CEXP, v+62, x}, {TW_CEXP, v+63, x}, \
	{TW_CEXP, v+64, x}, {TW_CEXP, v+65, x}, {TW_CEXP, v+66, x}, {TW_CEXP, v+67, x}, \
	{TW_CEXP, v+68, x}, {TW_CEXP, v+69, x}, {TW_CEXP, v+70, x}, {TW_CEXP, v+71, x}, \
	{TW_CEXP, v+72, x}, {TW_CEXP, v+73, x}, {TW_CEXP, v+74, x}, {TW_CEXP, v+75, x}, \
	{TW_CEXP, v+76, x}, {TW_CEXP, v+77, x}, {TW_CEXP, v+78, x}, {TW_CEXP, v+79, x}, \
	{TW_CEXP, v+80, x}, {TW_CEXP, v+81, x}, {TW_CEXP, v+82, x}, {TW_CEXP, v+83, x}, \
	{TW_CEXP, v+84, x}, {TW_CEXP, v+85, x}, {TW_CEXP, v+86, x}, {TW_CEXP, v+87, x}, \
	{TW_CEXP, v+88, x}, {TW_CEXP, v+89, x}, {TW_CEXP, v+90, x}, {TW_CEXP, v+91, x}, \
	{TW_CEXP, v+92, x}, {TW_CEXP, v+93, x}, {TW_CEXP, v+94, x}, {TW_CEXP, v+95, x}, \
	{TW_CEXP, v+96, x}, {TW_CEXP, v+97, x}, {TW_CEXP, v+98, x}, {TW_CEXP, v+99, x}, \
	{TW_CEXP, v+100, x}, {TW_CEXP, v+101, x}, {TW_CEXP, v+102, x}, {TW_CEXP, v+103, x}, \
	{TW_CEXP, v+104, x}, {TW_CEXP, v+105, x}, {TW_CEXP, v+106, x}, {TW_CEXP, v+107, x}, \
	{TW_CEXP, v+108, x}, {TW_CEXP, v+109, x}, {TW_CEXP, v+110, x}, {TW_CEXP, v+111, x}, \
	{TW_CEXP, v+112, x}, {TW_CEXP, v+113, x}, {TW_CEXP, v+114, x}, {TW_CEXP, v+115, x}, \
	{TW_CEXP, v+116, x}, {TW_CEXP, v+117, x}, {TW_CEXP, v+118, x}, {TW_CEXP, v+119, x}, \
	{TW_CEXP, v+120, x}, {TW_CEXP, v+121, x}, {TW_CEXP, v+122, x}, {TW_CEXP, v+123, x}, \
	{TW_CEXP, v+124, x}, {TW_CEXP, v+125, x}, {TW_CEXP, v+126, x}, {TW_CEXP, v+127, x}, \
	{TW_CEXP, v+128, x}, {TW_CEXP, v+129, x}, {TW_CEXP, v+130, x}, {TW_CEXP, v+131, x}, \
	{TW_CEXP, v+132, x}, {TW_CEXP, v+133, x}, {TW_CEXP, v+134, x}, {TW_CEXP, v+135, x}, \
	{TW_CEXP, v+136, x}, {TW_CEXP, v+137, x}, {TW_CEXP, v+138, x}, {TW_CEXP, v+139, x}, \
	{TW_CEXP, v+140, x}, {TW_CEXP, v+141, x}, {TW_CEXP, v+142, x}, {TW_CEXP, v+143, x}, \
	{TW_CEXP, v+144, x}, {TW_CEXP, v+145, x}, {TW_CEXP, v+146, x}, {TW_CEXP, v+147, x}, \
	{TW_CEXP, v+148, x}, {TW_CEXP, v+149, x}, {TW_CEXP, v+150, x}, {TW_CEXP, v+151, x}, \
	{TW_CEXP, v+152, x}, {TW_CEXP, v+153, x}, {TW_CEXP, v+154, x}, {TW_CEXP, v+155, x}, \
	{TW_CEXP, v+156, x}, {TW_CEXP, v+157, x}, {TW_CEXP, v+158, x}, {TW_CEXP, v+159, x}, \
	{TW_CEXP, v+160, x}, {TW_CEXP, v+161, x}, {TW_CEXP, v+162, x}, {TW_CEXP, v+163, x}, \
	{TW_CEXP, v+164, x}, {TW_CEXP, v+165, x}, {TW_CEXP, v+166, x}, {TW_CEXP, v+167, x}, \
	{TW_CEXP, v+168, x}, {TW_CEXP, v+169, x}, {TW_CEXP, v+170, x}, {TW_CEXP, v+171, x}, \
	{TW_CEXP, v+172, x}, {TW_CEXP, v+173, x}, {TW_CEXP, v+174, x}, {TW_CEXP, v+175, x}, \
	{TW_CEXP, v+176, x}, {TW_CEXP, v+177, x}, {TW_CEXP, v+178, x}, {TW_CEXP, v+179, x}, \
	{TW_CEXP, v+180, x}, {TW_CEXP, v+181, x}, {TW_CEXP, v+182, x}, {TW_CEXP, v+183, x}, \
	{TW_CEXP, v+184, x}, {TW_CEXP, v+185, x}, {TW_CEXP, v+186, x}, {TW_CEXP, v+187, x}, \
	{TW_CEXP, v+188, x}, {TW_CEXP, v+189, x}, {TW_CEXP, v+190, x}, {TW_CEXP, v+191, x}, \
	{TW_CEXP, v+192, x}, {TW_CEXP, v+193, x}, {TW_CEXP, v+194, x}, {TW_CEXP, v+195, x}, \
	{TW_CEXP, v+196, x}, {TW_CEXP, v+197, x}, {TW_CEXP, v+198, x}, {TW_CEXP, v+199, x}, \
	{TW_CEXP, v+200, x}, {TW_CEXP, v+201, x}, {TW_CEXP, v+202, x}, {TW_CEXP, v+203, x}, \
	{TW_CEXP, v+204, x}, {TW_CEXP, v+205, x}, {TW_CEXP, v+206, x}, {TW_CEXP, v+207, x}, \
	{TW_CEXP, v+208, x}, {TW_CEXP, v+209, x}, {TW_CEXP, v+210, x}, {TW_CEXP, v+211, x}, \
	{TW_CEXP, v+212, x}, {TW_CEXP, v+213, x}, {TW_CEXP, v+214, x}, {TW_CEXP, v+215, x}, \
	{TW_CEXP, v+216, x}, {TW_CEXP, v+217, x}, {TW_CEXP, v+218, x}, {TW_CEXP, v+219, x}, \
	{TW_CEXP, v+220, x}, {TW_CEXP, v+221, x}, {TW_CEXP, v+222, x}, {TW_CEXP, v+223, x}, \
	{TW_CEXP, v+224, x}, {TW_CEXP, v+225, x}, {TW_CEXP, v+226, x}, {TW_CEXP, v+227, x}, \
	{TW_CEXP, v+228, x}, {TW_CEXP, v+229, x}, {TW_CEXP, v+230, x}, {TW_CEXP, v+231, x}, \
	{TW_CEXP, v+232, x}, {TW_CEXP, v+233, x}, {TW_CEXP, v+234, x}, {TW_CEXP, v+235, x}, \
	{TW_CEXP, v+236, x}, {TW_CEXP, v+237, x}, {TW_CEXP, v+238, x}, {TW_CEXP, v+239, x}, \
	{TW_CEXP, v+240, x}, {TW_CEXP, v+241, x}, {TW_CEXP, v+242, x}, {TW_CEXP, v+243, x}, \
	{TW_CEXP, v+244, x}, {TW_CEXP, v+245, x}, {TW_CEXP, v+246, x}, {TW_CEXP, v+247, x}, \
	{TW_CEXP, v+248, x}, {TW_CEXP, v+249, x}, {TW_CEXP, v+250, x}, {TW_CEXP, v+251, x}, \
	{TW_CEXP, v+252, x}, {TW_CEXP, v+253, x}, {TW_CEXP, v+254, x}, {TW_CEXP, v+255, x} 
#endif // VTW_SIZE == 256
#if defined(VTW_SIZE) && VTW_SIZE == 512
#warning "using VTW1 with 512"
#define VTW1(v,x) {TW_CEXP, v+0, x}, {TW_CEXP, v+1, x}, {TW_CEXP, v+2, x}, {TW_CEXP, v+3, x}, \
	{TW_CEXP, v+4, x}, {TW_CEXP, v+5, x}, {TW_CEXP, v+6, x}, {TW_CEXP, v+7, x}, \
	{TW_CEXP, v+8, x}, {TW_CEXP, v+9, x}, {TW_CEXP, v+10, x}, {TW_CEXP, v+11, x}, \
	{TW_CEXP, v+12, x}, {TW_CEXP, v+13, x}, {TW_CEXP, v+14, x}, {TW_CEXP, v+15, x}, \
	{TW_CEXP, v+16, x}, {TW_CEXP, v+17, x}, {TW_CEXP, v+18, x}, {TW_CEXP, v+19, x}, \
	{TW_CEXP, v+20, x}, {TW_CEXP, v+21, x}, {TW_CEXP, v+22, x}, {TW_CEXP, v+23, x}, \
	{TW_CEXP, v+24, x}, {TW_CEXP, v+25, x}, {TW_CEXP, v+26, x}, {TW_CEXP, v+27, x}, \
	{TW_CEXP, v+28, x}, {TW_CEXP, v+29, x}, {TW_CEXP, v+30, x}, {TW_CEXP, v+31, x}, \
	{TW_CEXP, v+32, x}, {TW_CEXP, v+33, x}, {TW_CEXP, v+34, x}, {TW_CEXP, v+35, x}, \
	{TW_CEXP, v+36, x}, {TW_CEXP, v+37, x}, {TW_CEXP, v+38, x}, {TW_CEXP, v+39, x}, \
	{TW_CEXP, v+40, x}, {TW_CEXP, v+41, x}, {TW_CEXP, v+42, x}, {TW_CEXP, v+43, x}, \
	{TW_CEXP, v+44, x}, {TW_CEXP, v+45, x}, {TW_CEXP, v+46, x}, {TW_CEXP, v+47, x}, \
	{TW_CEXP, v+48, x}, {TW_CEXP, v+49, x}, {TW_CEXP, v+50, x}, {TW_CEXP, v+51, x}, \
	{TW_CEXP, v+52, x}, {TW_CEXP, v+53, x}, {TW_CEXP, v+54, x}, {TW_CEXP, v+55, x}, \
	{TW_CEXP, v+56, x}, {TW_CEXP, v+57, x}, {TW_CEXP, v+58, x}, {TW_CEXP, v+59, x}, \
	{TW_CEXP, v+60, x}, {TW_CEXP, v+61, x}, {TW_CEXP, v+62, x}, {TW_CEXP, v+63, x}, \
	{TW_CEXP, v+64, x}, {TW_CEXP, v+65, x}, {TW_CEXP, v+66, x}, {TW_CEXP, v+67, x}, \
	{TW_CEXP, v+68, x}, {TW_CEXP, v+69, x}, {TW_CEXP, v+70, x}, {TW_CEXP, v+71, x}, \
	{TW_CEXP, v+72, x}, {TW_CEXP, v+73, x}, {TW_CEXP, v+74, x}, {TW_CEXP, v+75, x}, \
	{TW_CEXP, v+76, x}, {TW_CEXP, v+77, x}, {TW_CEXP, v+78, x}, {TW_CEXP, v+79, x}, \
	{TW_CEXP, v+80, x}, {TW_CEXP, v+81, x}, {TW_CEXP, v+82, x}, {TW_CEXP, v+83, x}, \
	{TW_CEXP, v+84, x}, {TW_CEXP, v+85, x}, {TW_CEXP, v+86, x}, {TW_CEXP, v+87, x}, \
	{TW_CEXP, v+88, x}, {TW_CEXP, v+89, x}, {TW_CEXP, v+90, x}, {TW_CEXP, v+91, x}, \
	{TW_CEXP, v+92, x}, {TW_CEXP, v+93, x}, {TW_CEXP, v+94, x}, {TW_CEXP, v+95, x}, \
	{TW_CEXP, v+96, x}, {TW_CEXP, v+97, x}, {TW_CEXP, v+98, x}, {TW_CEXP, v+99, x}, \
	{TW_CEXP, v+100, x}, {TW_CEXP, v+101, x}, {TW_CEXP, v+102, x}, {TW_CEXP, v+103, x}, \
	{TW_CEXP, v+104, x}, {TW_CEXP, v+105, x}, {TW_CEXP, v+106, x}, {TW_CEXP, v+107, x}, \
	{TW_CEXP, v+108, x}, {TW_CEXP, v+109, x}, {TW_CEXP, v+110, x}, {TW_CEXP, v+111, x}, \
	{TW_CEXP, v+112, x}, {TW_CEXP, v+113, x}, {TW_CEXP, v+114, x}, {TW_CEXP, v+115, x}, \
	{TW_CEXP, v+116, x}, {TW_CEXP, v+117, x}, {TW_CEXP, v+118, x}, {TW_CEXP, v+119, x}, \
	{TW_CEXP, v+120, x}, {TW_CEXP, v+121, x}, {TW_CEXP, v+122, x}, {TW_CEXP, v+123, x}, \
	{TW_CEXP, v+124, x}, {TW_CEXP, v+125, x}, {TW_CEXP, v+126, x}, {TW_CEXP, v+127, x}, \
	{TW_CEXP, v+128, x}, {TW_CEXP, v+129, x}, {TW_CEXP, v+130, x}, {TW_CEXP, v+131, x}, \
	{TW_CEXP, v+132, x}, {TW_CEXP, v+133, x}, {TW_CEXP, v+134, x}, {TW_CEXP, v+135, x}, \
	{TW_CEXP, v+136, x}, {TW_CEXP, v+137, x}, {TW_CEXP, v+138, x}, {TW_CEXP, v+139, x}, \
	{TW_CEXP, v+140, x}, {TW_CEXP, v+141, x}, {TW_CEXP, v+142, x}, {TW_CEXP, v+143, x}, \
	{TW_CEXP, v+144, x}, {TW_CEXP, v+145, x}, {TW_CEXP, v+146, x}, {TW_CEXP, v+147, x}, \
	{TW_CEXP, v+148, x}, {TW_CEXP, v+149, x}, {TW_CEXP, v+150, x}, {TW_CEXP, v+151, x}, \
	{TW_CEXP, v+152, x}, {TW_CEXP, v+153, x}, {TW_CEXP, v+154, x}, {TW_CEXP, v+155, x}, \
	{TW_CEXP, v+156, x}, {TW_CEXP, v+157, x}, {TW_CEXP, v+158, x}, {TW_CEXP, v+159, x}, \
	{TW_CEXP, v+160, x}, {TW_CEXP, v+161, x}, {TW_CEXP, v+162, x}, {TW_CEXP, v+163, x}, \
	{TW_CEXP, v+164, x}, {TW_CEXP, v+165, x}, {TW_CEXP, v+166, x}, {TW_CEXP, v+167, x}, \
	{TW_CEXP, v+168, x}, {TW_CEXP, v+169, x}, {TW_CEXP, v+170, x}, {TW_CEXP, v+171, x}, \
	{TW_CEXP, v+172, x}, {TW_CEXP, v+173, x}, {TW_CEXP, v+174, x}, {TW_CEXP, v+175, x}, \
	{TW_CEXP, v+176, x}, {TW_CEXP, v+177, x}, {TW_CEXP, v+178, x}, {TW_CEXP, v+179, x}, \
	{TW_CEXP, v+180, x}, {TW_CEXP, v+181, x}, {TW_CEXP, v+182, x}, {TW_CEXP, v+183, x}, \
	{TW_CEXP, v+184, x}, {TW_CEXP, v+185, x}, {TW_CEXP, v+186, x}, {TW_CEXP, v+187, x}, \
	{TW_CEXP, v+188, x}, {TW_CEXP, v+189, x}, {TW_CEXP, v+190, x}, {TW_CEXP, v+191, x}, \
	{TW_CEXP, v+192, x}, {TW_CEXP, v+193, x}, {TW_CEXP, v+194, x}, {TW_CEXP, v+195, x}, \
	{TW_CEXP, v+196, x}, {TW_CEXP, v+197, x}, {TW_CEXP, v+198, x}, {TW_CEXP, v+199, x}, \
	{TW_CEXP, v+200, x}, {TW_CEXP, v+201, x}, {TW_CEXP, v+202, x}, {TW_CEXP, v+203, x}, \
	{TW_CEXP, v+204, x}, {TW_CEXP, v+205, x}, {TW_CEXP, v+206, x}, {TW_CEXP, v+207, x}, \
	{TW_CEXP, v+208, x}, {TW_CEXP, v+209, x}, {TW_CEXP, v+210, x}, {TW_CEXP, v+211, x}, \
	{TW_CEXP, v+212, x}, {TW_CEXP, v+213, x}, {TW_CEXP, v+214, x}, {TW_CEXP, v+215, x}, \
	{TW_CEXP, v+216, x}, {TW_CEXP, v+217, x}, {TW_CEXP, v+218, x}, {TW_CEXP, v+219, x}, \
	{TW_CEXP, v+220, x}, {TW_CEXP, v+221, x}, {TW_CEXP, v+222, x}, {TW_CEXP, v+223, x}, \
	{TW_CEXP, v+224, x}, {TW_CEXP, v+225, x}, {TW_CEXP, v+226, x}, {TW_CEXP, v+227, x}, \
	{TW_CEXP, v+228, x}, {TW_CEXP, v+229, x}, {TW_CEXP, v+230, x}, {TW_CEXP, v+231, x}, \
	{TW_CEXP, v+232, x}, {TW_CEXP, v+233, x}, {TW_CEXP, v+234, x}, {TW_CEXP, v+235, x}, \
	{TW_CEXP, v+236, x}, {TW_CEXP, v+237, x}, {TW_CEXP, v+238, x}, {TW_CEXP, v+239, x}, \
	{TW_CEXP, v+240, x}, {TW_CEXP, v+241, x}, {TW_CEXP, v+242, x}, {TW_CEXP, v+243, x}, \
	{TW_CEXP, v+244, x}, {TW_CEXP, v+245, x}, {TW_CEXP, v+246, x}, {TW_CEXP, v+247, x}, \
	{TW_CEXP, v+248, x}, {TW_CEXP, v+249, x}, {TW_CEXP, v+250, x}, {TW_CEXP, v+251, x}, \
	{TW_CEXP, v+252, x}, {TW_CEXP, v+253, x}, {TW_CEXP, v+254, x}, {TW_CEXP, v+255, x}, \
	{TW_CEXP, v+256, x}, {TW_CEXP, v+257, x}, {TW_CEXP, v+258, x}, {TW_CEXP, v+259, x}, \
	{TW_CEXP, v+260, x}, {TW_CEXP, v+261, x}, {TW_CEXP, v+262, x}, {TW_CEXP, v+263, x}, \
	{TW_CEXP, v+264, x}, {TW_CEXP, v+265, x}, {TW_CEXP, v+266, x}, {TW_CEXP, v+267, x}, \
	{TW_CEXP, v+268, x}, {TW_CEXP, v+269, x}, {TW_CEXP, v+270, x}, {TW_CEXP, v+271, x}, \
	{TW_CEXP, v+272, x}, {TW_CEXP, v+273, x}, {TW_CEXP, v+274, x}, {TW_CEXP, v+275, x}, \
	{TW_CEXP, v+276, x}, {TW_CEXP, v+277, x}, {TW_CEXP, v+278, x}, {TW_CEXP, v+279, x}, \
	{TW_CEXP, v+280, x}, {TW_CEXP, v+281, x}, {TW_CEXP, v+282, x}, {TW_CEXP, v+283, x}, \
	{TW_CEXP, v+284, x}, {TW_CEXP, v+285, x}, {TW_CEXP, v+286, x}, {TW_CEXP, v+287, x}, \
	{TW_CEXP, v+288, x}, {TW_CEXP, v+289, x}, {TW_CEXP, v+290, x}, {TW_CEXP, v+291, x}, \
	{TW_CEXP, v+292, x}, {TW_CEXP, v+293, x}, {TW_CEXP, v+294, x}, {TW_CEXP, v+295, x}, \
	{TW_CEXP, v+296, x}, {TW_CEXP, v+297, x}, {TW_CEXP, v+298, x}, {TW_CEXP, v+299, x}, \
	{TW_CEXP, v+300, x}, {TW_CEXP, v+301, x}, {TW_CEXP, v+302, x}, {TW_CEXP, v+303, x}, \
	{TW_CEXP, v+304, x}, {TW_CEXP, v+305, x}, {TW_CEXP, v+306, x}, {TW_CEXP, v+307, x}, \
	{TW_CEXP, v+308, x}, {TW_CEXP, v+309, x}, {TW_CEXP, v+310, x}, {TW_CEXP, v+311, x}, \
	{TW_CEXP, v+312, x}, {TW_CEXP, v+313, x}, {TW_CEXP, v+314, x}, {TW_CEXP, v+315, x}, \
	{TW_CEXP, v+316, x}, {TW_CEXP, v+317, x}, {TW_CEXP, v+318, x}, {TW_CEXP, v+319, x}, \
	{TW_CEXP, v+320, x}, {TW_CEXP, v+321, x}, {TW_CEXP, v+322, x}, {TW_CEXP, v+323, x}, \
	{TW_CEXP, v+324, x}, {TW_CEXP, v+325, x}, {TW_CEXP, v+326, x}, {TW_CEXP, v+327, x}, \
	{TW_CEXP, v+328, x}, {TW_CEXP, v+329, x}, {TW_CEXP, v+330, x}, {TW_CEXP, v+331, x}, \
	{TW_CEXP, v+332, x}, {TW_CEXP, v+333, x}, {TW_CEXP, v+334, x}, {TW_CEXP, v+335, x}, \
	{TW_CEXP, v+336, x}, {TW_CEXP, v+337, x}, {TW_CEXP, v+338, x}, {TW_CEXP, v+339, x}, \
	{TW_CEXP, v+340, x}, {TW_CEXP, v+341, x}, {TW_CEXP, v+342, x}, {TW_CEXP, v+343, x}, \
	{TW_CEXP, v+344, x}, {TW_CEXP, v+345, x}, {TW_CEXP, v+346, x}, {TW_CEXP, v+347, x}, \
	{TW_CEXP, v+348, x}, {TW_CEXP, v+349, x}, {TW_CEXP, v+350, x}, {TW_CEXP, v+351, x}, \
	{TW_CEXP, v+352, x}, {TW_CEXP, v+353, x}, {TW_CEXP, v+354, x}, {TW_CEXP, v+355, x}, \
	{TW_CEXP, v+356, x}, {TW_CEXP, v+357, x}, {TW_CEXP, v+358, x}, {TW_CEXP, v+359, x}, \
	{TW_CEXP, v+360, x}, {TW_CEXP, v+361, x}, {TW_CEXP, v+362, x}, {TW_CEXP, v+363, x}, \
	{TW_CEXP, v+364, x}, {TW_CEXP, v+365, x}, {TW_CEXP, v+366, x}, {TW_CEXP, v+367, x}, \
	{TW_CEXP, v+368, x}, {TW_CEXP, v+369, x}, {TW_CEXP, v+370, x}, {TW_CEXP, v+371, x}, \
	{TW_CEXP, v+372, x}, {TW_CEXP, v+373, x}, {TW_CEXP, v+374, x}, {TW_CEXP, v+375, x}, \
	{TW_CEXP, v+376, x}, {TW_CEXP, v+377, x}, {TW_CEXP, v+378, x}, {TW_CEXP, v+379, x}, \
	{TW_CEXP, v+380, x}, {TW_CEXP, v+381, x}, {TW_CEXP, v+382, x}, {TW_CEXP, v+383, x}, \
	{TW_CEXP, v+384, x}, {TW_CEXP, v+385, x}, {TW_CEXP, v+386, x}, {TW_CEXP, v+387, x}, \
	{TW_CEXP, v+388, x}, {TW_CEXP, v+389, x}, {TW_CEXP, v+390, x}, {TW_CEXP, v+391, x}, \
	{TW_CEXP, v+392, x}, {TW_CEXP, v+393, x}, {TW_CEXP, v+394, x}, {TW_CEXP, v+395, x}, \
	{TW_CEXP, v+396, x}, {TW_CEXP, v+397, x}, {TW_CEXP, v+398, x}, {TW_CEXP, v+399, x}, \
	{TW_CEXP, v+400, x}, {TW_CEXP, v+401, x}, {TW_CEXP, v+402, x}, {TW_CEXP, v+403, x}, \
	{TW_CEXP, v+404, x}, {TW_CEXP, v+405, x}, {TW_CEXP, v+406, x}, {TW_CEXP, v+407, x}, \
	{TW_CEXP, v+408, x}, {TW_CEXP, v+409, x}, {TW_CEXP, v+410, x}, {TW_CEXP, v+411, x}, \
	{TW_CEXP, v+412, x}, {TW_CEXP, v+413, x}, {TW_CEXP, v+414, x}, {TW_CEXP, v+415, x}, \
	{TW_CEXP, v+416, x}, {TW_CEXP, v+417, x}, {TW_CEXP, v+418, x}, {TW_CEXP, v+419, x}, \
	{TW_CEXP, v+420, x}, {TW_CEXP, v+421, x}, {TW_CEXP, v+422, x}, {TW_CEXP, v+423, x}, \
	{TW_CEXP, v+424, x}, {TW_CEXP, v+425, x}, {TW_CEXP, v+426, x}, {TW_CEXP, v+427, x}, \
	{TW_CEXP, v+428, x}, {TW_CEXP, v+429, x}, {TW_CEXP, v+430, x}, {TW_CEXP, v+431, x}, \
	{TW_CEXP, v+432, x}, {TW_CEXP, v+433, x}, {TW_CEXP, v+434, x}, {TW_CEXP, v+435, x}, \
	{TW_CEXP, v+436, x}, {TW_CEXP, v+437, x}, {TW_CEXP, v+438, x}, {TW_CEXP, v+439, x}, \
	{TW_CEXP, v+440, x}, {TW_CEXP, v+441, x}, {TW_CEXP, v+442, x}, {TW_CEXP, v+443, x}, \
	{TW_CEXP, v+444, x}, {TW_CEXP, v+445, x}, {TW_CEXP, v+446, x}, {TW_CEXP, v+447, x}, \
	{TW_CEXP, v+448, x}, {TW_CEXP, v+449, x}, {TW_CEXP, v+450, x}, {TW_CEXP, v+451, x}, \
	{TW_CEXP, v+452, x}, {TW_CEXP, v+453, x}, {TW_CEXP, v+454, x}, {TW_CEXP, v+455, x}, \
	{TW_CEXP, v+456, x}, {TW_CEXP, v+457, x}, {TW_CEXP, v+458, x}, {TW_CEXP, v+459, x}, \
	{TW_CEXP, v+460, x}, {TW_CEXP, v+461, x}, {TW_CEXP, v+462, x}, {TW_CEXP, v+463, x}, \
	{TW_CEXP, v+464, x}, {TW_CEXP, v+465, x}, {TW_CEXP, v+466, x}, {TW_CEXP, v+467, x}, \
	{TW_CEXP, v+468, x}, {TW_CEXP, v+469, x}, {TW_CEXP, v+470, x}, {TW_CEXP, v+471, x}, \
	{TW_CEXP, v+472, x}, {TW_CEXP, v+473, x}, {TW_CEXP, v+474, x}, {TW_CEXP, v+475, x}, \
	{TW_CEXP, v+476, x}, {TW_CEXP, v+477, x}, {TW_CEXP, v+478, x}, {TW_CEXP, v+479, x}, \
	{TW_CEXP, v+480, x}, {TW_CEXP, v+481, x}, {TW_CEXP, v+482, x}, {TW_CEXP, v+483, x}, \
	{TW_CEXP, v+484, x}, {TW_CEXP, v+485, x}, {TW_CEXP, v+486, x}, {TW_CEXP, v+487, x}, \
	{TW_CEXP, v+488, x}, {TW_CEXP, v+489, x}, {TW_CEXP, v+490, x}, {TW_CEXP, v+491, x}, \
	{TW_CEXP, v+492, x}, {TW_CEXP, v+493, x}, {TW_CEXP, v+494, x}, {TW_CEXP, v+495, x}, \
	{TW_CEXP, v+496, x}, {TW_CEXP, v+497, x}, {TW_CEXP, v+498, x}, {TW_CEXP, v+499, x}, \
	{TW_CEXP, v+500, x}, {TW_CEXP, v+501, x}, {TW_CEXP, v+502, x}, {TW_CEXP, v+503, x}, \
	{TW_CEXP, v+504, x}, {TW_CEXP, v+505, x}, {TW_CEXP, v+506, x}, {TW_CEXP, v+507, x}, \
	{TW_CEXP, v+508, x}, {TW_CEXP, v+509, x}, {TW_CEXP, v+510, x}, {TW_CEXP, v+511, x} 
#endif // VTW_SIZE == 512
#endif // REQ_VTW1
#if defined(REQ_VTW2)
#if defined(VTW_SIZE) && VTW_SIZE == 1
#warning "using VTW2 with 1"
#define VTW2(v,x) {TW_COS, v+0, x}, {TW_SIN, v+0, -x} 
#endif // VTW_SIZE == 1
#if defined(VTW_SIZE) && VTW_SIZE == 2
#warning "using VTW2 with 2"
#define VTW2(v,x) {TW_COS, v+0, x}, {TW_COS, v+0, x}, {TW_SIN, v+0, -x}, {TW_SIN, v+0, x} 
#endif // VTW_SIZE == 2
#if defined(VTW_SIZE) && VTW_SIZE == 4
#warning "using VTW2 with 4"
#define VTW2(v,x) {TW_COS, v+0, x}, {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+1, x}, \
	{TW_SIN, v+0, -x}, {TW_SIN, v+0, x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x} 
#endif // VTW_SIZE == 4
#if defined(VTW_SIZE) && VTW_SIZE == 8
#warning "using VTW2 with 8"
#define VTW2(v,x) {TW_COS, v+0, x}, {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+1, x}, \
	{TW_COS, v+2, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, {TW_COS, v+3, x}, \
	{TW_SIN, v+0, -x}, {TW_SIN, v+0, x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}, \
	{TW_SIN, v+2, -x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, -x}, {TW_SIN, v+3, x} 
#endif // VTW_SIZE == 8
#if defined(VTW_SIZE) && VTW_SIZE == 16
#warning "using VTW2 with 16"
#define VTW2(v,x) {TW_COS, v+0, x}, {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+1, x}, \
	{TW_COS, v+2, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, {TW_COS, v+3, x}, \
	{TW_COS, v+4, x}, {TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+5, x}, \
	{TW_COS, v+6, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, {TW_COS, v+7, x}, \
	{TW_SIN, v+0, -x}, {TW_SIN, v+0, x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}, \
	{TW_SIN, v+2, -x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, -x}, {TW_SIN, v+3, x}, \
	{TW_SIN, v+4, -x}, {TW_SIN, v+4, x}, {TW_SIN, v+5, -x}, {TW_SIN, v+5, x}, \
	{TW_SIN, v+6, -x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, -x}, {TW_SIN, v+7, x} 
#endif // VTW_SIZE == 16
#if defined(VTW_SIZE) && VTW_SIZE == 32
#warning "using VTW2 with 32"
#define VTW2(v,x) {TW_COS, v+0, x}, {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+1, x}, \
	{TW_COS, v+2, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, {TW_COS, v+3, x}, \
	{TW_COS, v+4, x}, {TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+5, x}, \
	{TW_COS, v+6, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, {TW_COS, v+7, x}, \
	{TW_COS, v+8, x}, {TW_COS, v+8, x}, {TW_COS, v+9, x}, {TW_COS, v+9, x}, \
	{TW_COS, v+10, x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, {TW_COS, v+11, x}, \
	{TW_COS, v+12, x}, {TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+13, x}, \
	{TW_COS, v+14, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, {TW_COS, v+15, x}, \
	{TW_SIN, v+0, -x}, {TW_SIN, v+0, x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}, \
	{TW_SIN, v+2, -x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, -x}, {TW_SIN, v+3, x}, \
	{TW_SIN, v+4, -x}, {TW_SIN, v+4, x}, {TW_SIN, v+5, -x}, {TW_SIN, v+5, x}, \
	{TW_SIN, v+6, -x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, -x}, {TW_SIN, v+7, x}, \
	{TW_SIN, v+8, -x}, {TW_SIN, v+8, x}, {TW_SIN, v+9, -x}, {TW_SIN, v+9, x}, \
	{TW_SIN, v+10, -x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, -x}, {TW_SIN, v+11, x}, \
	{TW_SIN, v+12, -x}, {TW_SIN, v+12, x}, {TW_SIN, v+13, -x}, {TW_SIN, v+13, x}, \
	{TW_SIN, v+14, -x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, -x}, {TW_SIN, v+15, x} 
#endif // VTW_SIZE == 32
#if defined(VTW_SIZE) && VTW_SIZE == 64
#warning "using VTW2 with 64"
#define VTW2(v,x) {TW_COS, v+0, x}, {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+1, x}, \
	{TW_COS, v+2, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, {TW_COS, v+3, x}, \
	{TW_COS, v+4, x}, {TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+5, x}, \
	{TW_COS, v+6, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, {TW_COS, v+7, x}, \
	{TW_COS, v+8, x}, {TW_COS, v+8, x}, {TW_COS, v+9, x}, {TW_COS, v+9, x}, \
	{TW_COS, v+10, x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, {TW_COS, v+11, x}, \
	{TW_COS, v+12, x}, {TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+13, x}, \
	{TW_COS, v+14, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, {TW_COS, v+15, x}, \
	{TW_COS, v+16, x}, {TW_COS, v+16, x}, {TW_COS, v+17, x}, {TW_COS, v+17, x}, \
	{TW_COS, v+18, x}, {TW_COS, v+18, x}, {TW_COS, v+19, x}, {TW_COS, v+19, x}, \
	{TW_COS, v+20, x}, {TW_COS, v+20, x}, {TW_COS, v+21, x}, {TW_COS, v+21, x}, \
	{TW_COS, v+22, x}, {TW_COS, v+22, x}, {TW_COS, v+23, x}, {TW_COS, v+23, x}, \
	{TW_COS, v+24, x}, {TW_COS, v+24, x}, {TW_COS, v+25, x}, {TW_COS, v+25, x}, \
	{TW_COS, v+26, x}, {TW_COS, v+26, x}, {TW_COS, v+27, x}, {TW_COS, v+27, x}, \
	{TW_COS, v+28, x}, {TW_COS, v+28, x}, {TW_COS, v+29, x}, {TW_COS, v+29, x}, \
	{TW_COS, v+30, x}, {TW_COS, v+30, x}, {TW_COS, v+31, x}, {TW_COS, v+31, x}, \
	{TW_SIN, v+0, -x}, {TW_SIN, v+0, x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}, \
	{TW_SIN, v+2, -x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, -x}, {TW_SIN, v+3, x}, \
	{TW_SIN, v+4, -x}, {TW_SIN, v+4, x}, {TW_SIN, v+5, -x}, {TW_SIN, v+5, x}, \
	{TW_SIN, v+6, -x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, -x}, {TW_SIN, v+7, x}, \
	{TW_SIN, v+8, -x}, {TW_SIN, v+8, x}, {TW_SIN, v+9, -x}, {TW_SIN, v+9, x}, \
	{TW_SIN, v+10, -x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, -x}, {TW_SIN, v+11, x}, \
	{TW_SIN, v+12, -x}, {TW_SIN, v+12, x}, {TW_SIN, v+13, -x}, {TW_SIN, v+13, x}, \
	{TW_SIN, v+14, -x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, -x}, {TW_SIN, v+15, x}, \
	{TW_SIN, v+16, -x}, {TW_SIN, v+16, x}, {TW_SIN, v+17, -x}, {TW_SIN, v+17, x}, \
	{TW_SIN, v+18, -x}, {TW_SIN, v+18, x}, {TW_SIN, v+19, -x}, {TW_SIN, v+19, x}, \
	{TW_SIN, v+20, -x}, {TW_SIN, v+20, x}, {TW_SIN, v+21, -x}, {TW_SIN, v+21, x}, \
	{TW_SIN, v+22, -x}, {TW_SIN, v+22, x}, {TW_SIN, v+23, -x}, {TW_SIN, v+23, x}, \
	{TW_SIN, v+24, -x}, {TW_SIN, v+24, x}, {TW_SIN, v+25, -x}, {TW_SIN, v+25, x}, \
	{TW_SIN, v+26, -x}, {TW_SIN, v+26, x}, {TW_SIN, v+27, -x}, {TW_SIN, v+27, x}, \
	{TW_SIN, v+28, -x}, {TW_SIN, v+28, x}, {TW_SIN, v+29, -x}, {TW_SIN, v+29, x}, \
	{TW_SIN, v+30, -x}, {TW_SIN, v+30, x}, {TW_SIN, v+31, -x}, {TW_SIN, v+31, x} 
#endif // VTW_SIZE == 64
#if defined(VTW_SIZE) && VTW_SIZE == 128
#warning "using VTW2 with 128"
#define VTW2(v,x) {TW_COS, v+0, x}, {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+1, x}, \
	{TW_COS, v+2, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, {TW_COS, v+3, x}, \
	{TW_COS, v+4, x}, {TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+5, x}, \
	{TW_COS, v+6, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, {TW_COS, v+7, x}, \
	{TW_COS, v+8, x}, {TW_COS, v+8, x}, {TW_COS, v+9, x}, {TW_COS, v+9, x}, \
	{TW_COS, v+10, x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, {TW_COS, v+11, x}, \
	{TW_COS, v+12, x}, {TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+13, x}, \
	{TW_COS, v+14, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, {TW_COS, v+15, x}, \
	{TW_COS, v+16, x}, {TW_COS, v+16, x}, {TW_COS, v+17, x}, {TW_COS, v+17, x}, \
	{TW_COS, v+18, x}, {TW_COS, v+18, x}, {TW_COS, v+19, x}, {TW_COS, v+19, x}, \
	{TW_COS, v+20, x}, {TW_COS, v+20, x}, {TW_COS, v+21, x}, {TW_COS, v+21, x}, \
	{TW_COS, v+22, x}, {TW_COS, v+22, x}, {TW_COS, v+23, x}, {TW_COS, v+23, x}, \
	{TW_COS, v+24, x}, {TW_COS, v+24, x}, {TW_COS, v+25, x}, {TW_COS, v+25, x}, \
	{TW_COS, v+26, x}, {TW_COS, v+26, x}, {TW_COS, v+27, x}, {TW_COS, v+27, x}, \
	{TW_COS, v+28, x}, {TW_COS, v+28, x}, {TW_COS, v+29, x}, {TW_COS, v+29, x}, \
	{TW_COS, v+30, x}, {TW_COS, v+30, x}, {TW_COS, v+31, x}, {TW_COS, v+31, x}, \
	{TW_COS, v+32, x}, {TW_COS, v+32, x}, {TW_COS, v+33, x}, {TW_COS, v+33, x}, \
	{TW_COS, v+34, x}, {TW_COS, v+34, x}, {TW_COS, v+35, x}, {TW_COS, v+35, x}, \
	{TW_COS, v+36, x}, {TW_COS, v+36, x}, {TW_COS, v+37, x}, {TW_COS, v+37, x}, \
	{TW_COS, v+38, x}, {TW_COS, v+38, x}, {TW_COS, v+39, x}, {TW_COS, v+39, x}, \
	{TW_COS, v+40, x}, {TW_COS, v+40, x}, {TW_COS, v+41, x}, {TW_COS, v+41, x}, \
	{TW_COS, v+42, x}, {TW_COS, v+42, x}, {TW_COS, v+43, x}, {TW_COS, v+43, x}, \
	{TW_COS, v+44, x}, {TW_COS, v+44, x}, {TW_COS, v+45, x}, {TW_COS, v+45, x}, \
	{TW_COS, v+46, x}, {TW_COS, v+46, x}, {TW_COS, v+47, x}, {TW_COS, v+47, x}, \
	{TW_COS, v+48, x}, {TW_COS, v+48, x}, {TW_COS, v+49, x}, {TW_COS, v+49, x}, \
	{TW_COS, v+50, x}, {TW_COS, v+50, x}, {TW_COS, v+51, x}, {TW_COS, v+51, x}, \
	{TW_COS, v+52, x}, {TW_COS, v+52, x}, {TW_COS, v+53, x}, {TW_COS, v+53, x}, \
	{TW_COS, v+54, x}, {TW_COS, v+54, x}, {TW_COS, v+55, x}, {TW_COS, v+55, x}, \
	{TW_COS, v+56, x}, {TW_COS, v+56, x}, {TW_COS, v+57, x}, {TW_COS, v+57, x}, \
	{TW_COS, v+58, x}, {TW_COS, v+58, x}, {TW_COS, v+59, x}, {TW_COS, v+59, x}, \
	{TW_COS, v+60, x}, {TW_COS, v+60, x}, {TW_COS, v+61, x}, {TW_COS, v+61, x}, \
	{TW_COS, v+62, x}, {TW_COS, v+62, x}, {TW_COS, v+63, x}, {TW_COS, v+63, x}, \
	{TW_SIN, v+0, -x}, {TW_SIN, v+0, x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}, \
	{TW_SIN, v+2, -x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, -x}, {TW_SIN, v+3, x}, \
	{TW_SIN, v+4, -x}, {TW_SIN, v+4, x}, {TW_SIN, v+5, -x}, {TW_SIN, v+5, x}, \
	{TW_SIN, v+6, -x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, -x}, {TW_SIN, v+7, x}, \
	{TW_SIN, v+8, -x}, {TW_SIN, v+8, x}, {TW_SIN, v+9, -x}, {TW_SIN, v+9, x}, \
	{TW_SIN, v+10, -x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, -x}, {TW_SIN, v+11, x}, \
	{TW_SIN, v+12, -x}, {TW_SIN, v+12, x}, {TW_SIN, v+13, -x}, {TW_SIN, v+13, x}, \
	{TW_SIN, v+14, -x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, -x}, {TW_SIN, v+15, x}, \
	{TW_SIN, v+16, -x}, {TW_SIN, v+16, x}, {TW_SIN, v+17, -x}, {TW_SIN, v+17, x}, \
	{TW_SIN, v+18, -x}, {TW_SIN, v+18, x}, {TW_SIN, v+19, -x}, {TW_SIN, v+19, x}, \
	{TW_SIN, v+20, -x}, {TW_SIN, v+20, x}, {TW_SIN, v+21, -x}, {TW_SIN, v+21, x}, \
	{TW_SIN, v+22, -x}, {TW_SIN, v+22, x}, {TW_SIN, v+23, -x}, {TW_SIN, v+23, x}, \
	{TW_SIN, v+24, -x}, {TW_SIN, v+24, x}, {TW_SIN, v+25, -x}, {TW_SIN, v+25, x}, \
	{TW_SIN, v+26, -x}, {TW_SIN, v+26, x}, {TW_SIN, v+27, -x}, {TW_SIN, v+27, x}, \
	{TW_SIN, v+28, -x}, {TW_SIN, v+28, x}, {TW_SIN, v+29, -x}, {TW_SIN, v+29, x}, \
	{TW_SIN, v+30, -x}, {TW_SIN, v+30, x}, {TW_SIN, v+31, -x}, {TW_SIN, v+31, x}, \
	{TW_SIN, v+32, -x}, {TW_SIN, v+32, x}, {TW_SIN, v+33, -x}, {TW_SIN, v+33, x}, \
	{TW_SIN, v+34, -x}, {TW_SIN, v+34, x}, {TW_SIN, v+35, -x}, {TW_SIN, v+35, x}, \
	{TW_SIN, v+36, -x}, {TW_SIN, v+36, x}, {TW_SIN, v+37, -x}, {TW_SIN, v+37, x}, \
	{TW_SIN, v+38, -x}, {TW_SIN, v+38, x}, {TW_SIN, v+39, -x}, {TW_SIN, v+39, x}, \
	{TW_SIN, v+40, -x}, {TW_SIN, v+40, x}, {TW_SIN, v+41, -x}, {TW_SIN, v+41, x}, \
	{TW_SIN, v+42, -x}, {TW_SIN, v+42, x}, {TW_SIN, v+43, -x}, {TW_SIN, v+43, x}, \
	{TW_SIN, v+44, -x}, {TW_SIN, v+44, x}, {TW_SIN, v+45, -x}, {TW_SIN, v+45, x}, \
	{TW_SIN, v+46, -x}, {TW_SIN, v+46, x}, {TW_SIN, v+47, -x}, {TW_SIN, v+47, x}, \
	{TW_SIN, v+48, -x}, {TW_SIN, v+48, x}, {TW_SIN, v+49, -x}, {TW_SIN, v+49, x}, \
	{TW_SIN, v+50, -x}, {TW_SIN, v+50, x}, {TW_SIN, v+51, -x}, {TW_SIN, v+51, x}, \
	{TW_SIN, v+52, -x}, {TW_SIN, v+52, x}, {TW_SIN, v+53, -x}, {TW_SIN, v+53, x}, \
	{TW_SIN, v+54, -x}, {TW_SIN, v+54, x}, {TW_SIN, v+55, -x}, {TW_SIN, v+55, x}, \
	{TW_SIN, v+56, -x}, {TW_SIN, v+56, x}, {TW_SIN, v+57, -x}, {TW_SIN, v+57, x}, \
	{TW_SIN, v+58, -x}, {TW_SIN, v+58, x}, {TW_SIN, v+59, -x}, {TW_SIN, v+59, x}, \
	{TW_SIN, v+60, -x}, {TW_SIN, v+60, x}, {TW_SIN, v+61, -x}, {TW_SIN, v+61, x}, \
	{TW_SIN, v+62, -x}, {TW_SIN, v+62, x}, {TW_SIN, v+63, -x}, {TW_SIN, v+63, x} 
#endif // VTW_SIZE == 128
#if defined(VTW_SIZE) && VTW_SIZE == 256
#warning "using VTW2 with 256"
#define VTW2(v,x) {TW_COS, v+0, x}, {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+1, x}, \
	{TW_COS, v+2, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, {TW_COS, v+3, x}, \
	{TW_COS, v+4, x}, {TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+5, x}, \
	{TW_COS, v+6, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, {TW_COS, v+7, x}, \
	{TW_COS, v+8, x}, {TW_COS, v+8, x}, {TW_COS, v+9, x}, {TW_COS, v+9, x}, \
	{TW_COS, v+10, x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, {TW_COS, v+11, x}, \
	{TW_COS, v+12, x}, {TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+13, x}, \
	{TW_COS, v+14, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, {TW_COS, v+15, x}, \
	{TW_COS, v+16, x}, {TW_COS, v+16, x}, {TW_COS, v+17, x}, {TW_COS, v+17, x}, \
	{TW_COS, v+18, x}, {TW_COS, v+18, x}, {TW_COS, v+19, x}, {TW_COS, v+19, x}, \
	{TW_COS, v+20, x}, {TW_COS, v+20, x}, {TW_COS, v+21, x}, {TW_COS, v+21, x}, \
	{TW_COS, v+22, x}, {TW_COS, v+22, x}, {TW_COS, v+23, x}, {TW_COS, v+23, x}, \
	{TW_COS, v+24, x}, {TW_COS, v+24, x}, {TW_COS, v+25, x}, {TW_COS, v+25, x}, \
	{TW_COS, v+26, x}, {TW_COS, v+26, x}, {TW_COS, v+27, x}, {TW_COS, v+27, x}, \
	{TW_COS, v+28, x}, {TW_COS, v+28, x}, {TW_COS, v+29, x}, {TW_COS, v+29, x}, \
	{TW_COS, v+30, x}, {TW_COS, v+30, x}, {TW_COS, v+31, x}, {TW_COS, v+31, x}, \
	{TW_COS, v+32, x}, {TW_COS, v+32, x}, {TW_COS, v+33, x}, {TW_COS, v+33, x}, \
	{TW_COS, v+34, x}, {TW_COS, v+34, x}, {TW_COS, v+35, x}, {TW_COS, v+35, x}, \
	{TW_COS, v+36, x}, {TW_COS, v+36, x}, {TW_COS, v+37, x}, {TW_COS, v+37, x}, \
	{TW_COS, v+38, x}, {TW_COS, v+38, x}, {TW_COS, v+39, x}, {TW_COS, v+39, x}, \
	{TW_COS, v+40, x}, {TW_COS, v+40, x}, {TW_COS, v+41, x}, {TW_COS, v+41, x}, \
	{TW_COS, v+42, x}, {TW_COS, v+42, x}, {TW_COS, v+43, x}, {TW_COS, v+43, x}, \
	{TW_COS, v+44, x}, {TW_COS, v+44, x}, {TW_COS, v+45, x}, {TW_COS, v+45, x}, \
	{TW_COS, v+46, x}, {TW_COS, v+46, x}, {TW_COS, v+47, x}, {TW_COS, v+47, x}, \
	{TW_COS, v+48, x}, {TW_COS, v+48, x}, {TW_COS, v+49, x}, {TW_COS, v+49, x}, \
	{TW_COS, v+50, x}, {TW_COS, v+50, x}, {TW_COS, v+51, x}, {TW_COS, v+51, x}, \
	{TW_COS, v+52, x}, {TW_COS, v+52, x}, {TW_COS, v+53, x}, {TW_COS, v+53, x}, \
	{TW_COS, v+54, x}, {TW_COS, v+54, x}, {TW_COS, v+55, x}, {TW_COS, v+55, x}, \
	{TW_COS, v+56, x}, {TW_COS, v+56, x}, {TW_COS, v+57, x}, {TW_COS, v+57, x}, \
	{TW_COS, v+58, x}, {TW_COS, v+58, x}, {TW_COS, v+59, x}, {TW_COS, v+59, x}, \
	{TW_COS, v+60, x}, {TW_COS, v+60, x}, {TW_COS, v+61, x}, {TW_COS, v+61, x}, \
	{TW_COS, v+62, x}, {TW_COS, v+62, x}, {TW_COS, v+63, x}, {TW_COS, v+63, x}, \
	{TW_COS, v+64, x}, {TW_COS, v+64, x}, {TW_COS, v+65, x}, {TW_COS, v+65, x}, \
	{TW_COS, v+66, x}, {TW_COS, v+66, x}, {TW_COS, v+67, x}, {TW_COS, v+67, x}, \
	{TW_COS, v+68, x}, {TW_COS, v+68, x}, {TW_COS, v+69, x}, {TW_COS, v+69, x}, \
	{TW_COS, v+70, x}, {TW_COS, v+70, x}, {TW_COS, v+71, x}, {TW_COS, v+71, x}, \
	{TW_COS, v+72, x}, {TW_COS, v+72, x}, {TW_COS, v+73, x}, {TW_COS, v+73, x}, \
	{TW_COS, v+74, x}, {TW_COS, v+74, x}, {TW_COS, v+75, x}, {TW_COS, v+75, x}, \
	{TW_COS, v+76, x}, {TW_COS, v+76, x}, {TW_COS, v+77, x}, {TW_COS, v+77, x}, \
	{TW_COS, v+78, x}, {TW_COS, v+78, x}, {TW_COS, v+79, x}, {TW_COS, v+79, x}, \
	{TW_COS, v+80, x}, {TW_COS, v+80, x}, {TW_COS, v+81, x}, {TW_COS, v+81, x}, \
	{TW_COS, v+82, x}, {TW_COS, v+82, x}, {TW_COS, v+83, x}, {TW_COS, v+83, x}, \
	{TW_COS, v+84, x}, {TW_COS, v+84, x}, {TW_COS, v+85, x}, {TW_COS, v+85, x}, \
	{TW_COS, v+86, x}, {TW_COS, v+86, x}, {TW_COS, v+87, x}, {TW_COS, v+87, x}, \
	{TW_COS, v+88, x}, {TW_COS, v+88, x}, {TW_COS, v+89, x}, {TW_COS, v+89, x}, \
	{TW_COS, v+90, x}, {TW_COS, v+90, x}, {TW_COS, v+91, x}, {TW_COS, v+91, x}, \
	{TW_COS, v+92, x}, {TW_COS, v+92, x}, {TW_COS, v+93, x}, {TW_COS, v+93, x}, \
	{TW_COS, v+94, x}, {TW_COS, v+94, x}, {TW_COS, v+95, x}, {TW_COS, v+95, x}, \
	{TW_COS, v+96, x}, {TW_COS, v+96, x}, {TW_COS, v+97, x}, {TW_COS, v+97, x}, \
	{TW_COS, v+98, x}, {TW_COS, v+98, x}, {TW_COS, v+99, x}, {TW_COS, v+99, x}, \
	{TW_COS, v+100, x}, {TW_COS, v+100, x}, {TW_COS, v+101, x}, {TW_COS, v+101, x}, \
	{TW_COS, v+102, x}, {TW_COS, v+102, x}, {TW_COS, v+103, x}, {TW_COS, v+103, x}, \
	{TW_COS, v+104, x}, {TW_COS, v+104, x}, {TW_COS, v+105, x}, {TW_COS, v+105, x}, \
	{TW_COS, v+106, x}, {TW_COS, v+106, x}, {TW_COS, v+107, x}, {TW_COS, v+107, x}, \
	{TW_COS, v+108, x}, {TW_COS, v+108, x}, {TW_COS, v+109, x}, {TW_COS, v+109, x}, \
	{TW_COS, v+110, x}, {TW_COS, v+110, x}, {TW_COS, v+111, x}, {TW_COS, v+111, x}, \
	{TW_COS, v+112, x}, {TW_COS, v+112, x}, {TW_COS, v+113, x}, {TW_COS, v+113, x}, \
	{TW_COS, v+114, x}, {TW_COS, v+114, x}, {TW_COS, v+115, x}, {TW_COS, v+115, x}, \
	{TW_COS, v+116, x}, {TW_COS, v+116, x}, {TW_COS, v+117, x}, {TW_COS, v+117, x}, \
	{TW_COS, v+118, x}, {TW_COS, v+118, x}, {TW_COS, v+119, x}, {TW_COS, v+119, x}, \
	{TW_COS, v+120, x}, {TW_COS, v+120, x}, {TW_COS, v+121, x}, {TW_COS, v+121, x}, \
	{TW_COS, v+122, x}, {TW_COS, v+122, x}, {TW_COS, v+123, x}, {TW_COS, v+123, x}, \
	{TW_COS, v+124, x}, {TW_COS, v+124, x}, {TW_COS, v+125, x}, {TW_COS, v+125, x}, \
	{TW_COS, v+126, x}, {TW_COS, v+126, x}, {TW_COS, v+127, x}, {TW_COS, v+127, x}, \
	{TW_SIN, v+0, -x}, {TW_SIN, v+0, x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}, \
	{TW_SIN, v+2, -x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, -x}, {TW_SIN, v+3, x}, \
	{TW_SIN, v+4, -x}, {TW_SIN, v+4, x}, {TW_SIN, v+5, -x}, {TW_SIN, v+5, x}, \
	{TW_SIN, v+6, -x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, -x}, {TW_SIN, v+7, x}, \
	{TW_SIN, v+8, -x}, {TW_SIN, v+8, x}, {TW_SIN, v+9, -x}, {TW_SIN, v+9, x}, \
	{TW_SIN, v+10, -x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, -x}, {TW_SIN, v+11, x}, \
	{TW_SIN, v+12, -x}, {TW_SIN, v+12, x}, {TW_SIN, v+13, -x}, {TW_SIN, v+13, x}, \
	{TW_SIN, v+14, -x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, -x}, {TW_SIN, v+15, x}, \
	{TW_SIN, v+16, -x}, {TW_SIN, v+16, x}, {TW_SIN, v+17, -x}, {TW_SIN, v+17, x}, \
	{TW_SIN, v+18, -x}, {TW_SIN, v+18, x}, {TW_SIN, v+19, -x}, {TW_SIN, v+19, x}, \
	{TW_SIN, v+20, -x}, {TW_SIN, v+20, x}, {TW_SIN, v+21, -x}, {TW_SIN, v+21, x}, \
	{TW_SIN, v+22, -x}, {TW_SIN, v+22, x}, {TW_SIN, v+23, -x}, {TW_SIN, v+23, x}, \
	{TW_SIN, v+24, -x}, {TW_SIN, v+24, x}, {TW_SIN, v+25, -x}, {TW_SIN, v+25, x}, \
	{TW_SIN, v+26, -x}, {TW_SIN, v+26, x}, {TW_SIN, v+27, -x}, {TW_SIN, v+27, x}, \
	{TW_SIN, v+28, -x}, {TW_SIN, v+28, x}, {TW_SIN, v+29, -x}, {TW_SIN, v+29, x}, \
	{TW_SIN, v+30, -x}, {TW_SIN, v+30, x}, {TW_SIN, v+31, -x}, {TW_SIN, v+31, x}, \
	{TW_SIN, v+32, -x}, {TW_SIN, v+32, x}, {TW_SIN, v+33, -x}, {TW_SIN, v+33, x}, \
	{TW_SIN, v+34, -x}, {TW_SIN, v+34, x}, {TW_SIN, v+35, -x}, {TW_SIN, v+35, x}, \
	{TW_SIN, v+36, -x}, {TW_SIN, v+36, x}, {TW_SIN, v+37, -x}, {TW_SIN, v+37, x}, \
	{TW_SIN, v+38, -x}, {TW_SIN, v+38, x}, {TW_SIN, v+39, -x}, {TW_SIN, v+39, x}, \
	{TW_SIN, v+40, -x}, {TW_SIN, v+40, x}, {TW_SIN, v+41, -x}, {TW_SIN, v+41, x}, \
	{TW_SIN, v+42, -x}, {TW_SIN, v+42, x}, {TW_SIN, v+43, -x}, {TW_SIN, v+43, x}, \
	{TW_SIN, v+44, -x}, {TW_SIN, v+44, x}, {TW_SIN, v+45, -x}, {TW_SIN, v+45, x}, \
	{TW_SIN, v+46, -x}, {TW_SIN, v+46, x}, {TW_SIN, v+47, -x}, {TW_SIN, v+47, x}, \
	{TW_SIN, v+48, -x}, {TW_SIN, v+48, x}, {TW_SIN, v+49, -x}, {TW_SIN, v+49, x}, \
	{TW_SIN, v+50, -x}, {TW_SIN, v+50, x}, {TW_SIN, v+51, -x}, {TW_SIN, v+51, x}, \
	{TW_SIN, v+52, -x}, {TW_SIN, v+52, x}, {TW_SIN, v+53, -x}, {TW_SIN, v+53, x}, \
	{TW_SIN, v+54, -x}, {TW_SIN, v+54, x}, {TW_SIN, v+55, -x}, {TW_SIN, v+55, x}, \
	{TW_SIN, v+56, -x}, {TW_SIN, v+56, x}, {TW_SIN, v+57, -x}, {TW_SIN, v+57, x}, \
	{TW_SIN, v+58, -x}, {TW_SIN, v+58, x}, {TW_SIN, v+59, -x}, {TW_SIN, v+59, x}, \
	{TW_SIN, v+60, -x}, {TW_SIN, v+60, x}, {TW_SIN, v+61, -x}, {TW_SIN, v+61, x}, \
	{TW_SIN, v+62, -x}, {TW_SIN, v+62, x}, {TW_SIN, v+63, -x}, {TW_SIN, v+63, x}, \
	{TW_SIN, v+64, -x}, {TW_SIN, v+64, x}, {TW_SIN, v+65, -x}, {TW_SIN, v+65, x}, \
	{TW_SIN, v+66, -x}, {TW_SIN, v+66, x}, {TW_SIN, v+67, -x}, {TW_SIN, v+67, x}, \
	{TW_SIN, v+68, -x}, {TW_SIN, v+68, x}, {TW_SIN, v+69, -x}, {TW_SIN, v+69, x}, \
	{TW_SIN, v+70, -x}, {TW_SIN, v+70, x}, {TW_SIN, v+71, -x}, {TW_SIN, v+71, x}, \
	{TW_SIN, v+72, -x}, {TW_SIN, v+72, x}, {TW_SIN, v+73, -x}, {TW_SIN, v+73, x}, \
	{TW_SIN, v+74, -x}, {TW_SIN, v+74, x}, {TW_SIN, v+75, -x}, {TW_SIN, v+75, x}, \
	{TW_SIN, v+76, -x}, {TW_SIN, v+76, x}, {TW_SIN, v+77, -x}, {TW_SIN, v+77, x}, \
	{TW_SIN, v+78, -x}, {TW_SIN, v+78, x}, {TW_SIN, v+79, -x}, {TW_SIN, v+79, x}, \
	{TW_SIN, v+80, -x}, {TW_SIN, v+80, x}, {TW_SIN, v+81, -x}, {TW_SIN, v+81, x}, \
	{TW_SIN, v+82, -x}, {TW_SIN, v+82, x}, {TW_SIN, v+83, -x}, {TW_SIN, v+83, x}, \
	{TW_SIN, v+84, -x}, {TW_SIN, v+84, x}, {TW_SIN, v+85, -x}, {TW_SIN, v+85, x}, \
	{TW_SIN, v+86, -x}, {TW_SIN, v+86, x}, {TW_SIN, v+87, -x}, {TW_SIN, v+87, x}, \
	{TW_SIN, v+88, -x}, {TW_SIN, v+88, x}, {TW_SIN, v+89, -x}, {TW_SIN, v+89, x}, \
	{TW_SIN, v+90, -x}, {TW_SIN, v+90, x}, {TW_SIN, v+91, -x}, {TW_SIN, v+91, x}, \
	{TW_SIN, v+92, -x}, {TW_SIN, v+92, x}, {TW_SIN, v+93, -x}, {TW_SIN, v+93, x}, \
	{TW_SIN, v+94, -x}, {TW_SIN, v+94, x}, {TW_SIN, v+95, -x}, {TW_SIN, v+95, x}, \
	{TW_SIN, v+96, -x}, {TW_SIN, v+96, x}, {TW_SIN, v+97, -x}, {TW_SIN, v+97, x}, \
	{TW_SIN, v+98, -x}, {TW_SIN, v+98, x}, {TW_SIN, v+99, -x}, {TW_SIN, v+99, x}, \
	{TW_SIN, v+100, -x}, {TW_SIN, v+100, x}, {TW_SIN, v+101, -x}, {TW_SIN, v+101, x}, \
	{TW_SIN, v+102, -x}, {TW_SIN, v+102, x}, {TW_SIN, v+103, -x}, {TW_SIN, v+103, x}, \
	{TW_SIN, v+104, -x}, {TW_SIN, v+104, x}, {TW_SIN, v+105, -x}, {TW_SIN, v+105, x}, \
	{TW_SIN, v+106, -x}, {TW_SIN, v+106, x}, {TW_SIN, v+107, -x}, {TW_SIN, v+107, x}, \
	{TW_SIN, v+108, -x}, {TW_SIN, v+108, x}, {TW_SIN, v+109, -x}, {TW_SIN, v+109, x}, \
	{TW_SIN, v+110, -x}, {TW_SIN, v+110, x}, {TW_SIN, v+111, -x}, {TW_SIN, v+111, x}, \
	{TW_SIN, v+112, -x}, {TW_SIN, v+112, x}, {TW_SIN, v+113, -x}, {TW_SIN, v+113, x}, \
	{TW_SIN, v+114, -x}, {TW_SIN, v+114, x}, {TW_SIN, v+115, -x}, {TW_SIN, v+115, x}, \
	{TW_SIN, v+116, -x}, {TW_SIN, v+116, x}, {TW_SIN, v+117, -x}, {TW_SIN, v+117, x}, \
	{TW_SIN, v+118, -x}, {TW_SIN, v+118, x}, {TW_SIN, v+119, -x}, {TW_SIN, v+119, x}, \
	{TW_SIN, v+120, -x}, {TW_SIN, v+120, x}, {TW_SIN, v+121, -x}, {TW_SIN, v+121, x}, \
	{TW_SIN, v+122, -x}, {TW_SIN, v+122, x}, {TW_SIN, v+123, -x}, {TW_SIN, v+123, x}, \
	{TW_SIN, v+124, -x}, {TW_SIN, v+124, x}, {TW_SIN, v+125, -x}, {TW_SIN, v+125, x}, \
	{TW_SIN, v+126, -x}, {TW_SIN, v+126, x}, {TW_SIN, v+127, -x}, {TW_SIN, v+127, x} 
#endif // VTW_SIZE == 256
#if defined(VTW_SIZE) && VTW_SIZE == 512
#warning "using VTW2 with 512"
#define VTW2(v,x) {TW_COS, v+0, x}, {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+1, x}, \
	{TW_COS, v+2, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, {TW_COS, v+3, x}, \
	{TW_COS, v+4, x}, {TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+5, x}, \
	{TW_COS, v+6, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, {TW_COS, v+7, x}, \
	{TW_COS, v+8, x}, {TW_COS, v+8, x}, {TW_COS, v+9, x}, {TW_COS, v+9, x}, \
	{TW_COS, v+10, x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, {TW_COS, v+11, x}, \
	{TW_COS, v+12, x}, {TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+13, x}, \
	{TW_COS, v+14, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, {TW_COS, v+15, x}, \
	{TW_COS, v+16, x}, {TW_COS, v+16, x}, {TW_COS, v+17, x}, {TW_COS, v+17, x}, \
	{TW_COS, v+18, x}, {TW_COS, v+18, x}, {TW_COS, v+19, x}, {TW_COS, v+19, x}, \
	{TW_COS, v+20, x}, {TW_COS, v+20, x}, {TW_COS, v+21, x}, {TW_COS, v+21, x}, \
	{TW_COS, v+22, x}, {TW_COS, v+22, x}, {TW_COS, v+23, x}, {TW_COS, v+23, x}, \
	{TW_COS, v+24, x}, {TW_COS, v+24, x}, {TW_COS, v+25, x}, {TW_COS, v+25, x}, \
	{TW_COS, v+26, x}, {TW_COS, v+26, x}, {TW_COS, v+27, x}, {TW_COS, v+27, x}, \
	{TW_COS, v+28, x}, {TW_COS, v+28, x}, {TW_COS, v+29, x}, {TW_COS, v+29, x}, \
	{TW_COS, v+30, x}, {TW_COS, v+30, x}, {TW_COS, v+31, x}, {TW_COS, v+31, x}, \
	{TW_COS, v+32, x}, {TW_COS, v+32, x}, {TW_COS, v+33, x}, {TW_COS, v+33, x}, \
	{TW_COS, v+34, x}, {TW_COS, v+34, x}, {TW_COS, v+35, x}, {TW_COS, v+35, x}, \
	{TW_COS, v+36, x}, {TW_COS, v+36, x}, {TW_COS, v+37, x}, {TW_COS, v+37, x}, \
	{TW_COS, v+38, x}, {TW_COS, v+38, x}, {TW_COS, v+39, x}, {TW_COS, v+39, x}, \
	{TW_COS, v+40, x}, {TW_COS, v+40, x}, {TW_COS, v+41, x}, {TW_COS, v+41, x}, \
	{TW_COS, v+42, x}, {TW_COS, v+42, x}, {TW_COS, v+43, x}, {TW_COS, v+43, x}, \
	{TW_COS, v+44, x}, {TW_COS, v+44, x}, {TW_COS, v+45, x}, {TW_COS, v+45, x}, \
	{TW_COS, v+46, x}, {TW_COS, v+46, x}, {TW_COS, v+47, x}, {TW_COS, v+47, x}, \
	{TW_COS, v+48, x}, {TW_COS, v+48, x}, {TW_COS, v+49, x}, {TW_COS, v+49, x}, \
	{TW_COS, v+50, x}, {TW_COS, v+50, x}, {TW_COS, v+51, x}, {TW_COS, v+51, x}, \
	{TW_COS, v+52, x}, {TW_COS, v+52, x}, {TW_COS, v+53, x}, {TW_COS, v+53, x}, \
	{TW_COS, v+54, x}, {TW_COS, v+54, x}, {TW_COS, v+55, x}, {TW_COS, v+55, x}, \
	{TW_COS, v+56, x}, {TW_COS, v+56, x}, {TW_COS, v+57, x}, {TW_COS, v+57, x}, \
	{TW_COS, v+58, x}, {TW_COS, v+58, x}, {TW_COS, v+59, x}, {TW_COS, v+59, x}, \
	{TW_COS, v+60, x}, {TW_COS, v+60, x}, {TW_COS, v+61, x}, {TW_COS, v+61, x}, \
	{TW_COS, v+62, x}, {TW_COS, v+62, x}, {TW_COS, v+63, x}, {TW_COS, v+63, x}, \
	{TW_COS, v+64, x}, {TW_COS, v+64, x}, {TW_COS, v+65, x}, {TW_COS, v+65, x}, \
	{TW_COS, v+66, x}, {TW_COS, v+66, x}, {TW_COS, v+67, x}, {TW_COS, v+67, x}, \
	{TW_COS, v+68, x}, {TW_COS, v+68, x}, {TW_COS, v+69, x}, {TW_COS, v+69, x}, \
	{TW_COS, v+70, x}, {TW_COS, v+70, x}, {TW_COS, v+71, x}, {TW_COS, v+71, x}, \
	{TW_COS, v+72, x}, {TW_COS, v+72, x}, {TW_COS, v+73, x}, {TW_COS, v+73, x}, \
	{TW_COS, v+74, x}, {TW_COS, v+74, x}, {TW_COS, v+75, x}, {TW_COS, v+75, x}, \
	{TW_COS, v+76, x}, {TW_COS, v+76, x}, {TW_COS, v+77, x}, {TW_COS, v+77, x}, \
	{TW_COS, v+78, x}, {TW_COS, v+78, x}, {TW_COS, v+79, x}, {TW_COS, v+79, x}, \
	{TW_COS, v+80, x}, {TW_COS, v+80, x}, {TW_COS, v+81, x}, {TW_COS, v+81, x}, \
	{TW_COS, v+82, x}, {TW_COS, v+82, x}, {TW_COS, v+83, x}, {TW_COS, v+83, x}, \
	{TW_COS, v+84, x}, {TW_COS, v+84, x}, {TW_COS, v+85, x}, {TW_COS, v+85, x}, \
	{TW_COS, v+86, x}, {TW_COS, v+86, x}, {TW_COS, v+87, x}, {TW_COS, v+87, x}, \
	{TW_COS, v+88, x}, {TW_COS, v+88, x}, {TW_COS, v+89, x}, {TW_COS, v+89, x}, \
	{TW_COS, v+90, x}, {TW_COS, v+90, x}, {TW_COS, v+91, x}, {TW_COS, v+91, x}, \
	{TW_COS, v+92, x}, {TW_COS, v+92, x}, {TW_COS, v+93, x}, {TW_COS, v+93, x}, \
	{TW_COS, v+94, x}, {TW_COS, v+94, x}, {TW_COS, v+95, x}, {TW_COS, v+95, x}, \
	{TW_COS, v+96, x}, {TW_COS, v+96, x}, {TW_COS, v+97, x}, {TW_COS, v+97, x}, \
	{TW_COS, v+98, x}, {TW_COS, v+98, x}, {TW_COS, v+99, x}, {TW_COS, v+99, x}, \
	{TW_COS, v+100, x}, {TW_COS, v+100, x}, {TW_COS, v+101, x}, {TW_COS, v+101, x}, \
	{TW_COS, v+102, x}, {TW_COS, v+102, x}, {TW_COS, v+103, x}, {TW_COS, v+103, x}, \
	{TW_COS, v+104, x}, {TW_COS, v+104, x}, {TW_COS, v+105, x}, {TW_COS, v+105, x}, \
	{TW_COS, v+106, x}, {TW_COS, v+106, x}, {TW_COS, v+107, x}, {TW_COS, v+107, x}, \
	{TW_COS, v+108, x}, {TW_COS, v+108, x}, {TW_COS, v+109, x}, {TW_COS, v+109, x}, \
	{TW_COS, v+110, x}, {TW_COS, v+110, x}, {TW_COS, v+111, x}, {TW_COS, v+111, x}, \
	{TW_COS, v+112, x}, {TW_COS, v+112, x}, {TW_COS, v+113, x}, {TW_COS, v+113, x}, \
	{TW_COS, v+114, x}, {TW_COS, v+114, x}, {TW_COS, v+115, x}, {TW_COS, v+115, x}, \
	{TW_COS, v+116, x}, {TW_COS, v+116, x}, {TW_COS, v+117, x}, {TW_COS, v+117, x}, \
	{TW_COS, v+118, x}, {TW_COS, v+118, x}, {TW_COS, v+119, x}, {TW_COS, v+119, x}, \
	{TW_COS, v+120, x}, {TW_COS, v+120, x}, {TW_COS, v+121, x}, {TW_COS, v+121, x}, \
	{TW_COS, v+122, x}, {TW_COS, v+122, x}, {TW_COS, v+123, x}, {TW_COS, v+123, x}, \
	{TW_COS, v+124, x}, {TW_COS, v+124, x}, {TW_COS, v+125, x}, {TW_COS, v+125, x}, \
	{TW_COS, v+126, x}, {TW_COS, v+126, x}, {TW_COS, v+127, x}, {TW_COS, v+127, x}, \
	{TW_COS, v+128, x}, {TW_COS, v+128, x}, {TW_COS, v+129, x}, {TW_COS, v+129, x}, \
	{TW_COS, v+130, x}, {TW_COS, v+130, x}, {TW_COS, v+131, x}, {TW_COS, v+131, x}, \
	{TW_COS, v+132, x}, {TW_COS, v+132, x}, {TW_COS, v+133, x}, {TW_COS, v+133, x}, \
	{TW_COS, v+134, x}, {TW_COS, v+134, x}, {TW_COS, v+135, x}, {TW_COS, v+135, x}, \
	{TW_COS, v+136, x}, {TW_COS, v+136, x}, {TW_COS, v+137, x}, {TW_COS, v+137, x}, \
	{TW_COS, v+138, x}, {TW_COS, v+138, x}, {TW_COS, v+139, x}, {TW_COS, v+139, x}, \
	{TW_COS, v+140, x}, {TW_COS, v+140, x}, {TW_COS, v+141, x}, {TW_COS, v+141, x}, \
	{TW_COS, v+142, x}, {TW_COS, v+142, x}, {TW_COS, v+143, x}, {TW_COS, v+143, x}, \
	{TW_COS, v+144, x}, {TW_COS, v+144, x}, {TW_COS, v+145, x}, {TW_COS, v+145, x}, \
	{TW_COS, v+146, x}, {TW_COS, v+146, x}, {TW_COS, v+147, x}, {TW_COS, v+147, x}, \
	{TW_COS, v+148, x}, {TW_COS, v+148, x}, {TW_COS, v+149, x}, {TW_COS, v+149, x}, \
	{TW_COS, v+150, x}, {TW_COS, v+150, x}, {TW_COS, v+151, x}, {TW_COS, v+151, x}, \
	{TW_COS, v+152, x}, {TW_COS, v+152, x}, {TW_COS, v+153, x}, {TW_COS, v+153, x}, \
	{TW_COS, v+154, x}, {TW_COS, v+154, x}, {TW_COS, v+155, x}, {TW_COS, v+155, x}, \
	{TW_COS, v+156, x}, {TW_COS, v+156, x}, {TW_COS, v+157, x}, {TW_COS, v+157, x}, \
	{TW_COS, v+158, x}, {TW_COS, v+158, x}, {TW_COS, v+159, x}, {TW_COS, v+159, x}, \
	{TW_COS, v+160, x}, {TW_COS, v+160, x}, {TW_COS, v+161, x}, {TW_COS, v+161, x}, \
	{TW_COS, v+162, x}, {TW_COS, v+162, x}, {TW_COS, v+163, x}, {TW_COS, v+163, x}, \
	{TW_COS, v+164, x}, {TW_COS, v+164, x}, {TW_COS, v+165, x}, {TW_COS, v+165, x}, \
	{TW_COS, v+166, x}, {TW_COS, v+166, x}, {TW_COS, v+167, x}, {TW_COS, v+167, x}, \
	{TW_COS, v+168, x}, {TW_COS, v+168, x}, {TW_COS, v+169, x}, {TW_COS, v+169, x}, \
	{TW_COS, v+170, x}, {TW_COS, v+170, x}, {TW_COS, v+171, x}, {TW_COS, v+171, x}, \
	{TW_COS, v+172, x}, {TW_COS, v+172, x}, {TW_COS, v+173, x}, {TW_COS, v+173, x}, \
	{TW_COS, v+174, x}, {TW_COS, v+174, x}, {TW_COS, v+175, x}, {TW_COS, v+175, x}, \
	{TW_COS, v+176, x}, {TW_COS, v+176, x}, {TW_COS, v+177, x}, {TW_COS, v+177, x}, \
	{TW_COS, v+178, x}, {TW_COS, v+178, x}, {TW_COS, v+179, x}, {TW_COS, v+179, x}, \
	{TW_COS, v+180, x}, {TW_COS, v+180, x}, {TW_COS, v+181, x}, {TW_COS, v+181, x}, \
	{TW_COS, v+182, x}, {TW_COS, v+182, x}, {TW_COS, v+183, x}, {TW_COS, v+183, x}, \
	{TW_COS, v+184, x}, {TW_COS, v+184, x}, {TW_COS, v+185, x}, {TW_COS, v+185, x}, \
	{TW_COS, v+186, x}, {TW_COS, v+186, x}, {TW_COS, v+187, x}, {TW_COS, v+187, x}, \
	{TW_COS, v+188, x}, {TW_COS, v+188, x}, {TW_COS, v+189, x}, {TW_COS, v+189, x}, \
	{TW_COS, v+190, x}, {TW_COS, v+190, x}, {TW_COS, v+191, x}, {TW_COS, v+191, x}, \
	{TW_COS, v+192, x}, {TW_COS, v+192, x}, {TW_COS, v+193, x}, {TW_COS, v+193, x}, \
	{TW_COS, v+194, x}, {TW_COS, v+194, x}, {TW_COS, v+195, x}, {TW_COS, v+195, x}, \
	{TW_COS, v+196, x}, {TW_COS, v+196, x}, {TW_COS, v+197, x}, {TW_COS, v+197, x}, \
	{TW_COS, v+198, x}, {TW_COS, v+198, x}, {TW_COS, v+199, x}, {TW_COS, v+199, x}, \
	{TW_COS, v+200, x}, {TW_COS, v+200, x}, {TW_COS, v+201, x}, {TW_COS, v+201, x}, \
	{TW_COS, v+202, x}, {TW_COS, v+202, x}, {TW_COS, v+203, x}, {TW_COS, v+203, x}, \
	{TW_COS, v+204, x}, {TW_COS, v+204, x}, {TW_COS, v+205, x}, {TW_COS, v+205, x}, \
	{TW_COS, v+206, x}, {TW_COS, v+206, x}, {TW_COS, v+207, x}, {TW_COS, v+207, x}, \
	{TW_COS, v+208, x}, {TW_COS, v+208, x}, {TW_COS, v+209, x}, {TW_COS, v+209, x}, \
	{TW_COS, v+210, x}, {TW_COS, v+210, x}, {TW_COS, v+211, x}, {TW_COS, v+211, x}, \
	{TW_COS, v+212, x}, {TW_COS, v+212, x}, {TW_COS, v+213, x}, {TW_COS, v+213, x}, \
	{TW_COS, v+214, x}, {TW_COS, v+214, x}, {TW_COS, v+215, x}, {TW_COS, v+215, x}, \
	{TW_COS, v+216, x}, {TW_COS, v+216, x}, {TW_COS, v+217, x}, {TW_COS, v+217, x}, \
	{TW_COS, v+218, x}, {TW_COS, v+218, x}, {TW_COS, v+219, x}, {TW_COS, v+219, x}, \
	{TW_COS, v+220, x}, {TW_COS, v+220, x}, {TW_COS, v+221, x}, {TW_COS, v+221, x}, \
	{TW_COS, v+222, x}, {TW_COS, v+222, x}, {TW_COS, v+223, x}, {TW_COS, v+223, x}, \
	{TW_COS, v+224, x}, {TW_COS, v+224, x}, {TW_COS, v+225, x}, {TW_COS, v+225, x}, \
	{TW_COS, v+226, x}, {TW_COS, v+226, x}, {TW_COS, v+227, x}, {TW_COS, v+227, x}, \
	{TW_COS, v+228, x}, {TW_COS, v+228, x}, {TW_COS, v+229, x}, {TW_COS, v+229, x}, \
	{TW_COS, v+230, x}, {TW_COS, v+230, x}, {TW_COS, v+231, x}, {TW_COS, v+231, x}, \
	{TW_COS, v+232, x}, {TW_COS, v+232, x}, {TW_COS, v+233, x}, {TW_COS, v+233, x}, \
	{TW_COS, v+234, x}, {TW_COS, v+234, x}, {TW_COS, v+235, x}, {TW_COS, v+235, x}, \
	{TW_COS, v+236, x}, {TW_COS, v+236, x}, {TW_COS, v+237, x}, {TW_COS, v+237, x}, \
	{TW_COS, v+238, x}, {TW_COS, v+238, x}, {TW_COS, v+239, x}, {TW_COS, v+239, x}, \
	{TW_COS, v+240, x}, {TW_COS, v+240, x}, {TW_COS, v+241, x}, {TW_COS, v+241, x}, \
	{TW_COS, v+242, x}, {TW_COS, v+242, x}, {TW_COS, v+243, x}, {TW_COS, v+243, x}, \
	{TW_COS, v+244, x}, {TW_COS, v+244, x}, {TW_COS, v+245, x}, {TW_COS, v+245, x}, \
	{TW_COS, v+246, x}, {TW_COS, v+246, x}, {TW_COS, v+247, x}, {TW_COS, v+247, x}, \
	{TW_COS, v+248, x}, {TW_COS, v+248, x}, {TW_COS, v+249, x}, {TW_COS, v+249, x}, \
	{TW_COS, v+250, x}, {TW_COS, v+250, x}, {TW_COS, v+251, x}, {TW_COS, v+251, x}, \
	{TW_COS, v+252, x}, {TW_COS, v+252, x}, {TW_COS, v+253, x}, {TW_COS, v+253, x}, \
	{TW_COS, v+254, x}, {TW_COS, v+254, x}, {TW_COS, v+255, x}, {TW_COS, v+255, x}, \
	{TW_SIN, v+0, -x}, {TW_SIN, v+0, x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}, \
	{TW_SIN, v+2, -x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, -x}, {TW_SIN, v+3, x}, \
	{TW_SIN, v+4, -x}, {TW_SIN, v+4, x}, {TW_SIN, v+5, -x}, {TW_SIN, v+5, x}, \
	{TW_SIN, v+6, -x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, -x}, {TW_SIN, v+7, x}, \
	{TW_SIN, v+8, -x}, {TW_SIN, v+8, x}, {TW_SIN, v+9, -x}, {TW_SIN, v+9, x}, \
	{TW_SIN, v+10, -x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, -x}, {TW_SIN, v+11, x}, \
	{TW_SIN, v+12, -x}, {TW_SIN, v+12, x}, {TW_SIN, v+13, -x}, {TW_SIN, v+13, x}, \
	{TW_SIN, v+14, -x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, -x}, {TW_SIN, v+15, x}, \
	{TW_SIN, v+16, -x}, {TW_SIN, v+16, x}, {TW_SIN, v+17, -x}, {TW_SIN, v+17, x}, \
	{TW_SIN, v+18, -x}, {TW_SIN, v+18, x}, {TW_SIN, v+19, -x}, {TW_SIN, v+19, x}, \
	{TW_SIN, v+20, -x}, {TW_SIN, v+20, x}, {TW_SIN, v+21, -x}, {TW_SIN, v+21, x}, \
	{TW_SIN, v+22, -x}, {TW_SIN, v+22, x}, {TW_SIN, v+23, -x}, {TW_SIN, v+23, x}, \
	{TW_SIN, v+24, -x}, {TW_SIN, v+24, x}, {TW_SIN, v+25, -x}, {TW_SIN, v+25, x}, \
	{TW_SIN, v+26, -x}, {TW_SIN, v+26, x}, {TW_SIN, v+27, -x}, {TW_SIN, v+27, x}, \
	{TW_SIN, v+28, -x}, {TW_SIN, v+28, x}, {TW_SIN, v+29, -x}, {TW_SIN, v+29, x}, \
	{TW_SIN, v+30, -x}, {TW_SIN, v+30, x}, {TW_SIN, v+31, -x}, {TW_SIN, v+31, x}, \
	{TW_SIN, v+32, -x}, {TW_SIN, v+32, x}, {TW_SIN, v+33, -x}, {TW_SIN, v+33, x}, \
	{TW_SIN, v+34, -x}, {TW_SIN, v+34, x}, {TW_SIN, v+35, -x}, {TW_SIN, v+35, x}, \
	{TW_SIN, v+36, -x}, {TW_SIN, v+36, x}, {TW_SIN, v+37, -x}, {TW_SIN, v+37, x}, \
	{TW_SIN, v+38, -x}, {TW_SIN, v+38, x}, {TW_SIN, v+39, -x}, {TW_SIN, v+39, x}, \
	{TW_SIN, v+40, -x}, {TW_SIN, v+40, x}, {TW_SIN, v+41, -x}, {TW_SIN, v+41, x}, \
	{TW_SIN, v+42, -x}, {TW_SIN, v+42, x}, {TW_SIN, v+43, -x}, {TW_SIN, v+43, x}, \
	{TW_SIN, v+44, -x}, {TW_SIN, v+44, x}, {TW_SIN, v+45, -x}, {TW_SIN, v+45, x}, \
	{TW_SIN, v+46, -x}, {TW_SIN, v+46, x}, {TW_SIN, v+47, -x}, {TW_SIN, v+47, x}, \
	{TW_SIN, v+48, -x}, {TW_SIN, v+48, x}, {TW_SIN, v+49, -x}, {TW_SIN, v+49, x}, \
	{TW_SIN, v+50, -x}, {TW_SIN, v+50, x}, {TW_SIN, v+51, -x}, {TW_SIN, v+51, x}, \
	{TW_SIN, v+52, -x}, {TW_SIN, v+52, x}, {TW_SIN, v+53, -x}, {TW_SIN, v+53, x}, \
	{TW_SIN, v+54, -x}, {TW_SIN, v+54, x}, {TW_SIN, v+55, -x}, {TW_SIN, v+55, x}, \
	{TW_SIN, v+56, -x}, {TW_SIN, v+56, x}, {TW_SIN, v+57, -x}, {TW_SIN, v+57, x}, \
	{TW_SIN, v+58, -x}, {TW_SIN, v+58, x}, {TW_SIN, v+59, -x}, {TW_SIN, v+59, x}, \
	{TW_SIN, v+60, -x}, {TW_SIN, v+60, x}, {TW_SIN, v+61, -x}, {TW_SIN, v+61, x}, \
	{TW_SIN, v+62, -x}, {TW_SIN, v+62, x}, {TW_SIN, v+63, -x}, {TW_SIN, v+63, x}, \
	{TW_SIN, v+64, -x}, {TW_SIN, v+64, x}, {TW_SIN, v+65, -x}, {TW_SIN, v+65, x}, \
	{TW_SIN, v+66, -x}, {TW_SIN, v+66, x}, {TW_SIN, v+67, -x}, {TW_SIN, v+67, x}, \
	{TW_SIN, v+68, -x}, {TW_SIN, v+68, x}, {TW_SIN, v+69, -x}, {TW_SIN, v+69, x}, \
	{TW_SIN, v+70, -x}, {TW_SIN, v+70, x}, {TW_SIN, v+71, -x}, {TW_SIN, v+71, x}, \
	{TW_SIN, v+72, -x}, {TW_SIN, v+72, x}, {TW_SIN, v+73, -x}, {TW_SIN, v+73, x}, \
	{TW_SIN, v+74, -x}, {TW_SIN, v+74, x}, {TW_SIN, v+75, -x}, {TW_SIN, v+75, x}, \
	{TW_SIN, v+76, -x}, {TW_SIN, v+76, x}, {TW_SIN, v+77, -x}, {TW_SIN, v+77, x}, \
	{TW_SIN, v+78, -x}, {TW_SIN, v+78, x}, {TW_SIN, v+79, -x}, {TW_SIN, v+79, x}, \
	{TW_SIN, v+80, -x}, {TW_SIN, v+80, x}, {TW_SIN, v+81, -x}, {TW_SIN, v+81, x}, \
	{TW_SIN, v+82, -x}, {TW_SIN, v+82, x}, {TW_SIN, v+83, -x}, {TW_SIN, v+83, x}, \
	{TW_SIN, v+84, -x}, {TW_SIN, v+84, x}, {TW_SIN, v+85, -x}, {TW_SIN, v+85, x}, \
	{TW_SIN, v+86, -x}, {TW_SIN, v+86, x}, {TW_SIN, v+87, -x}, {TW_SIN, v+87, x}, \
	{TW_SIN, v+88, -x}, {TW_SIN, v+88, x}, {TW_SIN, v+89, -x}, {TW_SIN, v+89, x}, \
	{TW_SIN, v+90, -x}, {TW_SIN, v+90, x}, {TW_SIN, v+91, -x}, {TW_SIN, v+91, x}, \
	{TW_SIN, v+92, -x}, {TW_SIN, v+92, x}, {TW_SIN, v+93, -x}, {TW_SIN, v+93, x}, \
	{TW_SIN, v+94, -x}, {TW_SIN, v+94, x}, {TW_SIN, v+95, -x}, {TW_SIN, v+95, x}, \
	{TW_SIN, v+96, -x}, {TW_SIN, v+96, x}, {TW_SIN, v+97, -x}, {TW_SIN, v+97, x}, \
	{TW_SIN, v+98, -x}, {TW_SIN, v+98, x}, {TW_SIN, v+99, -x}, {TW_SIN, v+99, x}, \
	{TW_SIN, v+100, -x}, {TW_SIN, v+100, x}, {TW_SIN, v+101, -x}, {TW_SIN, v+101, x}, \
	{TW_SIN, v+102, -x}, {TW_SIN, v+102, x}, {TW_SIN, v+103, -x}, {TW_SIN, v+103, x}, \
	{TW_SIN, v+104, -x}, {TW_SIN, v+104, x}, {TW_SIN, v+105, -x}, {TW_SIN, v+105, x}, \
	{TW_SIN, v+106, -x}, {TW_SIN, v+106, x}, {TW_SIN, v+107, -x}, {TW_SIN, v+107, x}, \
	{TW_SIN, v+108, -x}, {TW_SIN, v+108, x}, {TW_SIN, v+109, -x}, {TW_SIN, v+109, x}, \
	{TW_SIN, v+110, -x}, {TW_SIN, v+110, x}, {TW_SIN, v+111, -x}, {TW_SIN, v+111, x}, \
	{TW_SIN, v+112, -x}, {TW_SIN, v+112, x}, {TW_SIN, v+113, -x}, {TW_SIN, v+113, x}, \
	{TW_SIN, v+114, -x}, {TW_SIN, v+114, x}, {TW_SIN, v+115, -x}, {TW_SIN, v+115, x}, \
	{TW_SIN, v+116, -x}, {TW_SIN, v+116, x}, {TW_SIN, v+117, -x}, {TW_SIN, v+117, x}, \
	{TW_SIN, v+118, -x}, {TW_SIN, v+118, x}, {TW_SIN, v+119, -x}, {TW_SIN, v+119, x}, \
	{TW_SIN, v+120, -x}, {TW_SIN, v+120, x}, {TW_SIN, v+121, -x}, {TW_SIN, v+121, x}, \
	{TW_SIN, v+122, -x}, {TW_SIN, v+122, x}, {TW_SIN, v+123, -x}, {TW_SIN, v+123, x}, \
	{TW_SIN, v+124, -x}, {TW_SIN, v+124, x}, {TW_SIN, v+125, -x}, {TW_SIN, v+125, x}, \
	{TW_SIN, v+126, -x}, {TW_SIN, v+126, x}, {TW_SIN, v+127, -x}, {TW_SIN, v+127, x}, \
	{TW_SIN, v+128, -x}, {TW_SIN, v+128, x}, {TW_SIN, v+129, -x}, {TW_SIN, v+129, x}, \
	{TW_SIN, v+130, -x}, {TW_SIN, v+130, x}, {TW_SIN, v+131, -x}, {TW_SIN, v+131, x}, \
	{TW_SIN, v+132, -x}, {TW_SIN, v+132, x}, {TW_SIN, v+133, -x}, {TW_SIN, v+133, x}, \
	{TW_SIN, v+134, -x}, {TW_SIN, v+134, x}, {TW_SIN, v+135, -x}, {TW_SIN, v+135, x}, \
	{TW_SIN, v+136, -x}, {TW_SIN, v+136, x}, {TW_SIN, v+137, -x}, {TW_SIN, v+137, x}, \
	{TW_SIN, v+138, -x}, {TW_SIN, v+138, x}, {TW_SIN, v+139, -x}, {TW_SIN, v+139, x}, \
	{TW_SIN, v+140, -x}, {TW_SIN, v+140, x}, {TW_SIN, v+141, -x}, {TW_SIN, v+141, x}, \
	{TW_SIN, v+142, -x}, {TW_SIN, v+142, x}, {TW_SIN, v+143, -x}, {TW_SIN, v+143, x}, \
	{TW_SIN, v+144, -x}, {TW_SIN, v+144, x}, {TW_SIN, v+145, -x}, {TW_SIN, v+145, x}, \
	{TW_SIN, v+146, -x}, {TW_SIN, v+146, x}, {TW_SIN, v+147, -x}, {TW_SIN, v+147, x}, \
	{TW_SIN, v+148, -x}, {TW_SIN, v+148, x}, {TW_SIN, v+149, -x}, {TW_SIN, v+149, x}, \
	{TW_SIN, v+150, -x}, {TW_SIN, v+150, x}, {TW_SIN, v+151, -x}, {TW_SIN, v+151, x}, \
	{TW_SIN, v+152, -x}, {TW_SIN, v+152, x}, {TW_SIN, v+153, -x}, {TW_SIN, v+153, x}, \
	{TW_SIN, v+154, -x}, {TW_SIN, v+154, x}, {TW_SIN, v+155, -x}, {TW_SIN, v+155, x}, \
	{TW_SIN, v+156, -x}, {TW_SIN, v+156, x}, {TW_SIN, v+157, -x}, {TW_SIN, v+157, x}, \
	{TW_SIN, v+158, -x}, {TW_SIN, v+158, x}, {TW_SIN, v+159, -x}, {TW_SIN, v+159, x}, \
	{TW_SIN, v+160, -x}, {TW_SIN, v+160, x}, {TW_SIN, v+161, -x}, {TW_SIN, v+161, x}, \
	{TW_SIN, v+162, -x}, {TW_SIN, v+162, x}, {TW_SIN, v+163, -x}, {TW_SIN, v+163, x}, \
	{TW_SIN, v+164, -x}, {TW_SIN, v+164, x}, {TW_SIN, v+165, -x}, {TW_SIN, v+165, x}, \
	{TW_SIN, v+166, -x}, {TW_SIN, v+166, x}, {TW_SIN, v+167, -x}, {TW_SIN, v+167, x}, \
	{TW_SIN, v+168, -x}, {TW_SIN, v+168, x}, {TW_SIN, v+169, -x}, {TW_SIN, v+169, x}, \
	{TW_SIN, v+170, -x}, {TW_SIN, v+170, x}, {TW_SIN, v+171, -x}, {TW_SIN, v+171, x}, \
	{TW_SIN, v+172, -x}, {TW_SIN, v+172, x}, {TW_SIN, v+173, -x}, {TW_SIN, v+173, x}, \
	{TW_SIN, v+174, -x}, {TW_SIN, v+174, x}, {TW_SIN, v+175, -x}, {TW_SIN, v+175, x}, \
	{TW_SIN, v+176, -x}, {TW_SIN, v+176, x}, {TW_SIN, v+177, -x}, {TW_SIN, v+177, x}, \
	{TW_SIN, v+178, -x}, {TW_SIN, v+178, x}, {TW_SIN, v+179, -x}, {TW_SIN, v+179, x}, \
	{TW_SIN, v+180, -x}, {TW_SIN, v+180, x}, {TW_SIN, v+181, -x}, {TW_SIN, v+181, x}, \
	{TW_SIN, v+182, -x}, {TW_SIN, v+182, x}, {TW_SIN, v+183, -x}, {TW_SIN, v+183, x}, \
	{TW_SIN, v+184, -x}, {TW_SIN, v+184, x}, {TW_SIN, v+185, -x}, {TW_SIN, v+185, x}, \
	{TW_SIN, v+186, -x}, {TW_SIN, v+186, x}, {TW_SIN, v+187, -x}, {TW_SIN, v+187, x}, \
	{TW_SIN, v+188, -x}, {TW_SIN, v+188, x}, {TW_SIN, v+189, -x}, {TW_SIN, v+189, x}, \
	{TW_SIN, v+190, -x}, {TW_SIN, v+190, x}, {TW_SIN, v+191, -x}, {TW_SIN, v+191, x}, \
	{TW_SIN, v+192, -x}, {TW_SIN, v+192, x}, {TW_SIN, v+193, -x}, {TW_SIN, v+193, x}, \
	{TW_SIN, v+194, -x}, {TW_SIN, v+194, x}, {TW_SIN, v+195, -x}, {TW_SIN, v+195, x}, \
	{TW_SIN, v+196, -x}, {TW_SIN, v+196, x}, {TW_SIN, v+197, -x}, {TW_SIN, v+197, x}, \
	{TW_SIN, v+198, -x}, {TW_SIN, v+198, x}, {TW_SIN, v+199, -x}, {TW_SIN, v+199, x}, \
	{TW_SIN, v+200, -x}, {TW_SIN, v+200, x}, {TW_SIN, v+201, -x}, {TW_SIN, v+201, x}, \
	{TW_SIN, v+202, -x}, {TW_SIN, v+202, x}, {TW_SIN, v+203, -x}, {TW_SIN, v+203, x}, \
	{TW_SIN, v+204, -x}, {TW_SIN, v+204, x}, {TW_SIN, v+205, -x}, {TW_SIN, v+205, x}, \
	{TW_SIN, v+206, -x}, {TW_SIN, v+206, x}, {TW_SIN, v+207, -x}, {TW_SIN, v+207, x}, \
	{TW_SIN, v+208, -x}, {TW_SIN, v+208, x}, {TW_SIN, v+209, -x}, {TW_SIN, v+209, x}, \
	{TW_SIN, v+210, -x}, {TW_SIN, v+210, x}, {TW_SIN, v+211, -x}, {TW_SIN, v+211, x}, \
	{TW_SIN, v+212, -x}, {TW_SIN, v+212, x}, {TW_SIN, v+213, -x}, {TW_SIN, v+213, x}, \
	{TW_SIN, v+214, -x}, {TW_SIN, v+214, x}, {TW_SIN, v+215, -x}, {TW_SIN, v+215, x}, \
	{TW_SIN, v+216, -x}, {TW_SIN, v+216, x}, {TW_SIN, v+217, -x}, {TW_SIN, v+217, x}, \
	{TW_SIN, v+218, -x}, {TW_SIN, v+218, x}, {TW_SIN, v+219, -x}, {TW_SIN, v+219, x}, \
	{TW_SIN, v+220, -x}, {TW_SIN, v+220, x}, {TW_SIN, v+221, -x}, {TW_SIN, v+221, x}, \
	{TW_SIN, v+222, -x}, {TW_SIN, v+222, x}, {TW_SIN, v+223, -x}, {TW_SIN, v+223, x}, \
	{TW_SIN, v+224, -x}, {TW_SIN, v+224, x}, {TW_SIN, v+225, -x}, {TW_SIN, v+225, x}, \
	{TW_SIN, v+226, -x}, {TW_SIN, v+226, x}, {TW_SIN, v+227, -x}, {TW_SIN, v+227, x}, \
	{TW_SIN, v+228, -x}, {TW_SIN, v+228, x}, {TW_SIN, v+229, -x}, {TW_SIN, v+229, x}, \
	{TW_SIN, v+230, -x}, {TW_SIN, v+230, x}, {TW_SIN, v+231, -x}, {TW_SIN, v+231, x}, \
	{TW_SIN, v+232, -x}, {TW_SIN, v+232, x}, {TW_SIN, v+233, -x}, {TW_SIN, v+233, x}, \
	{TW_SIN, v+234, -x}, {TW_SIN, v+234, x}, {TW_SIN, v+235, -x}, {TW_SIN, v+235, x}, \
	{TW_SIN, v+236, -x}, {TW_SIN, v+236, x}, {TW_SIN, v+237, -x}, {TW_SIN, v+237, x}, \
	{TW_SIN, v+238, -x}, {TW_SIN, v+238, x}, {TW_SIN, v+239, -x}, {TW_SIN, v+239, x}, \
	{TW_SIN, v+240, -x}, {TW_SIN, v+240, x}, {TW_SIN, v+241, -x}, {TW_SIN, v+241, x}, \
	{TW_SIN, v+242, -x}, {TW_SIN, v+242, x}, {TW_SIN, v+243, -x}, {TW_SIN, v+243, x}, \
	{TW_SIN, v+244, -x}, {TW_SIN, v+244, x}, {TW_SIN, v+245, -x}, {TW_SIN, v+245, x}, \
	{TW_SIN, v+246, -x}, {TW_SIN, v+246, x}, {TW_SIN, v+247, -x}, {TW_SIN, v+247, x}, \
	{TW_SIN, v+248, -x}, {TW_SIN, v+248, x}, {TW_SIN, v+249, -x}, {TW_SIN, v+249, x}, \
	{TW_SIN, v+250, -x}, {TW_SIN, v+250, x}, {TW_SIN, v+251, -x}, {TW_SIN, v+251, x}, \
	{TW_SIN, v+252, -x}, {TW_SIN, v+252, x}, {TW_SIN, v+253, -x}, {TW_SIN, v+253, x}, \
	{TW_SIN, v+254, -x}, {TW_SIN, v+254, x}, {TW_SIN, v+255, -x}, {TW_SIN, v+255, x} 
#endif // VTW_SIZE == 512
#endif // REQ_VTW2
#if defined(REQ_VTWS)
#if defined(VTW_SIZE) && VTW_SIZE == 1
#warning "using VTWS with 1"
#define VTWS(v,x) {TW_COS, v+0, x}, {TW_SIN, v+0, x} 
#endif // VTW_SIZE == 1
#if defined(VTW_SIZE) && VTW_SIZE == 2
#warning "using VTWS with 2"
#define VTWS(v,x) {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_SIN, v+0, x}, {TW_SIN, v+1, x} 
#endif // VTW_SIZE == 2
#if defined(VTW_SIZE) && VTW_SIZE == 4
#warning "using VTWS with 4"
#define VTWS(v,x) {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, \
	{TW_SIN, v+0, x}, {TW_SIN, v+1, x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, x} 
#endif // VTW_SIZE == 4
#if defined(VTW_SIZE) && VTW_SIZE == 8
#warning "using VTWS with 8"
#define VTWS(v,x) {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, \
	{TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, \
	{TW_SIN, v+0, x}, {TW_SIN, v+1, x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, x}, \
	{TW_SIN, v+4, x}, {TW_SIN, v+5, x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, x} 
#endif // VTW_SIZE == 8
#if defined(VTW_SIZE) && VTW_SIZE == 16
#warning "using VTWS with 16"
#define VTWS(v,x) {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, \
	{TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, \
	{TW_COS, v+8, x}, {TW_COS, v+9, x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, \
	{TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, \
	{TW_SIN, v+0, x}, {TW_SIN, v+1, x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, x}, \
	{TW_SIN, v+4, x}, {TW_SIN, v+5, x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, x}, \
	{TW_SIN, v+8, x}, {TW_SIN, v+9, x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, x}, \
	{TW_SIN, v+12, x}, {TW_SIN, v+13, x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, x} 
#endif // VTW_SIZE == 16
#if defined(VTW_SIZE) && VTW_SIZE == 32
#warning "using VTWS with 32"
#define VTWS(v,x) {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, \
	{TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, \
	{TW_COS, v+8, x}, {TW_COS, v+9, x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, \
	{TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, \
	{TW_COS, v+16, x}, {TW_COS, v+17, x}, {TW_COS, v+18, x}, {TW_COS, v+19, x}, \
	{TW_COS, v+20, x}, {TW_COS, v+21, x}, {TW_COS, v+22, x}, {TW_COS, v+23, x}, \
	{TW_COS, v+24, x}, {TW_COS, v+25, x}, {TW_COS, v+26, x}, {TW_COS, v+27, x}, \
	{TW_COS, v+28, x}, {TW_COS, v+29, x}, {TW_COS, v+30, x}, {TW_COS, v+31, x}, \
	{TW_SIN, v+0, x}, {TW_SIN, v+1, x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, x}, \
	{TW_SIN, v+4, x}, {TW_SIN, v+5, x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, x}, \
	{TW_SIN, v+8, x}, {TW_SIN, v+9, x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, x}, \
	{TW_SIN, v+12, x}, {TW_SIN, v+13, x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, x}, \
	{TW_SIN, v+16, x}, {TW_SIN, v+17, x}, {TW_SIN, v+18, x}, {TW_SIN, v+19, x}, \
	{TW_SIN, v+20, x}, {TW_SIN, v+21, x}, {TW_SIN, v+22, x}, {TW_SIN, v+23, x}, \
	{TW_SIN, v+24, x}, {TW_SIN, v+25, x}, {TW_SIN, v+26, x}, {TW_SIN, v+27, x}, \
	{TW_SIN, v+28, x}, {TW_SIN, v+29, x}, {TW_SIN, v+30, x}, {TW_SIN, v+31, x} 
#endif // VTW_SIZE == 32
#if defined(VTW_SIZE) && VTW_SIZE == 64
#warning "using VTWS with 64"
#define VTWS(v,x) {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, \
	{TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, \
	{TW_COS, v+8, x}, {TW_COS, v+9, x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, \
	{TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, \
	{TW_COS, v+16, x}, {TW_COS, v+17, x}, {TW_COS, v+18, x}, {TW_COS, v+19, x}, \
	{TW_COS, v+20, x}, {TW_COS, v+21, x}, {TW_COS, v+22, x}, {TW_COS, v+23, x}, \
	{TW_COS, v+24, x}, {TW_COS, v+25, x}, {TW_COS, v+26, x}, {TW_COS, v+27, x}, \
	{TW_COS, v+28, x}, {TW_COS, v+29, x}, {TW_COS, v+30, x}, {TW_COS, v+31, x}, \
	{TW_COS, v+32, x}, {TW_COS, v+33, x}, {TW_COS, v+34, x}, {TW_COS, v+35, x}, \
	{TW_COS, v+36, x}, {TW_COS, v+37, x}, {TW_COS, v+38, x}, {TW_COS, v+39, x}, \
	{TW_COS, v+40, x}, {TW_COS, v+41, x}, {TW_COS, v+42, x}, {TW_COS, v+43, x}, \
	{TW_COS, v+44, x}, {TW_COS, v+45, x}, {TW_COS, v+46, x}, {TW_COS, v+47, x}, \
	{TW_COS, v+48, x}, {TW_COS, v+49, x}, {TW_COS, v+50, x}, {TW_COS, v+51, x}, \
	{TW_COS, v+52, x}, {TW_COS, v+53, x}, {TW_COS, v+54, x}, {TW_COS, v+55, x}, \
	{TW_COS, v+56, x}, {TW_COS, v+57, x}, {TW_COS, v+58, x}, {TW_COS, v+59, x}, \
	{TW_COS, v+60, x}, {TW_COS, v+61, x}, {TW_COS, v+62, x}, {TW_COS, v+63, x}, \
	{TW_SIN, v+0, x}, {TW_SIN, v+1, x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, x}, \
	{TW_SIN, v+4, x}, {TW_SIN, v+5, x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, x}, \
	{TW_SIN, v+8, x}, {TW_SIN, v+9, x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, x}, \
	{TW_SIN, v+12, x}, {TW_SIN, v+13, x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, x}, \
	{TW_SIN, v+16, x}, {TW_SIN, v+17, x}, {TW_SIN, v+18, x}, {TW_SIN, v+19, x}, \
	{TW_SIN, v+20, x}, {TW_SIN, v+21, x}, {TW_SIN, v+22, x}, {TW_SIN, v+23, x}, \
	{TW_SIN, v+24, x}, {TW_SIN, v+25, x}, {TW_SIN, v+26, x}, {TW_SIN, v+27, x}, \
	{TW_SIN, v+28, x}, {TW_SIN, v+29, x}, {TW_SIN, v+30, x}, {TW_SIN, v+31, x}, \
	{TW_SIN, v+32, x}, {TW_SIN, v+33, x}, {TW_SIN, v+34, x}, {TW_SIN, v+35, x}, \
	{TW_SIN, v+36, x}, {TW_SIN, v+37, x}, {TW_SIN, v+38, x}, {TW_SIN, v+39, x}, \
	{TW_SIN, v+40, x}, {TW_SIN, v+41, x}, {TW_SIN, v+42, x}, {TW_SIN, v+43, x}, \
	{TW_SIN, v+44, x}, {TW_SIN, v+45, x}, {TW_SIN, v+46, x}, {TW_SIN, v+47, x}, \
	{TW_SIN, v+48, x}, {TW_SIN, v+49, x}, {TW_SIN, v+50, x}, {TW_SIN, v+51, x}, \
	{TW_SIN, v+52, x}, {TW_SIN, v+53, x}, {TW_SIN, v+54, x}, {TW_SIN, v+55, x}, \
	{TW_SIN, v+56, x}, {TW_SIN, v+57, x}, {TW_SIN, v+58, x}, {TW_SIN, v+59, x}, \
	{TW_SIN, v+60, x}, {TW_SIN, v+61, x}, {TW_SIN, v+62, x}, {TW_SIN, v+63, x} 
#endif // VTW_SIZE == 64
#if defined(VTW_SIZE) && VTW_SIZE == 128
#warning "using VTWS with 128"
#define VTWS(v,x) {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, \
	{TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, \
	{TW_COS, v+8, x}, {TW_COS, v+9, x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, \
	{TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, \
	{TW_COS, v+16, x}, {TW_COS, v+17, x}, {TW_COS, v+18, x}, {TW_COS, v+19, x}, \
	{TW_COS, v+20, x}, {TW_COS, v+21, x}, {TW_COS, v+22, x}, {TW_COS, v+23, x}, \
	{TW_COS, v+24, x}, {TW_COS, v+25, x}, {TW_COS, v+26, x}, {TW_COS, v+27, x}, \
	{TW_COS, v+28, x}, {TW_COS, v+29, x}, {TW_COS, v+30, x}, {TW_COS, v+31, x}, \
	{TW_COS, v+32, x}, {TW_COS, v+33, x}, {TW_COS, v+34, x}, {TW_COS, v+35, x}, \
	{TW_COS, v+36, x}, {TW_COS, v+37, x}, {TW_COS, v+38, x}, {TW_COS, v+39, x}, \
	{TW_COS, v+40, x}, {TW_COS, v+41, x}, {TW_COS, v+42, x}, {TW_COS, v+43, x}, \
	{TW_COS, v+44, x}, {TW_COS, v+45, x}, {TW_COS, v+46, x}, {TW_COS, v+47, x}, \
	{TW_COS, v+48, x}, {TW_COS, v+49, x}, {TW_COS, v+50, x}, {TW_COS, v+51, x}, \
	{TW_COS, v+52, x}, {TW_COS, v+53, x}, {TW_COS, v+54, x}, {TW_COS, v+55, x}, \
	{TW_COS, v+56, x}, {TW_COS, v+57, x}, {TW_COS, v+58, x}, {TW_COS, v+59, x}, \
	{TW_COS, v+60, x}, {TW_COS, v+61, x}, {TW_COS, v+62, x}, {TW_COS, v+63, x}, \
	{TW_COS, v+64, x}, {TW_COS, v+65, x}, {TW_COS, v+66, x}, {TW_COS, v+67, x}, \
	{TW_COS, v+68, x}, {TW_COS, v+69, x}, {TW_COS, v+70, x}, {TW_COS, v+71, x}, \
	{TW_COS, v+72, x}, {TW_COS, v+73, x}, {TW_COS, v+74, x}, {TW_COS, v+75, x}, \
	{TW_COS, v+76, x}, {TW_COS, v+77, x}, {TW_COS, v+78, x}, {TW_COS, v+79, x}, \
	{TW_COS, v+80, x}, {TW_COS, v+81, x}, {TW_COS, v+82, x}, {TW_COS, v+83, x}, \
	{TW_COS, v+84, x}, {TW_COS, v+85, x}, {TW_COS, v+86, x}, {TW_COS, v+87, x}, \
	{TW_COS, v+88, x}, {TW_COS, v+89, x}, {TW_COS, v+90, x}, {TW_COS, v+91, x}, \
	{TW_COS, v+92, x}, {TW_COS, v+93, x}, {TW_COS, v+94, x}, {TW_COS, v+95, x}, \
	{TW_COS, v+96, x}, {TW_COS, v+97, x}, {TW_COS, v+98, x}, {TW_COS, v+99, x}, \
	{TW_COS, v+100, x}, {TW_COS, v+101, x}, {TW_COS, v+102, x}, {TW_COS, v+103, x}, \
	{TW_COS, v+104, x}, {TW_COS, v+105, x}, {TW_COS, v+106, x}, {TW_COS, v+107, x}, \
	{TW_COS, v+108, x}, {TW_COS, v+109, x}, {TW_COS, v+110, x}, {TW_COS, v+111, x}, \
	{TW_COS, v+112, x}, {TW_COS, v+113, x}, {TW_COS, v+114, x}, {TW_COS, v+115, x}, \
	{TW_COS, v+116, x}, {TW_COS, v+117, x}, {TW_COS, v+118, x}, {TW_COS, v+119, x}, \
	{TW_COS, v+120, x}, {TW_COS, v+121, x}, {TW_COS, v+122, x}, {TW_COS, v+123, x}, \
	{TW_COS, v+124, x}, {TW_COS, v+125, x}, {TW_COS, v+126, x}, {TW_COS, v+127, x}, \
	{TW_SIN, v+0, x}, {TW_SIN, v+1, x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, x}, \
	{TW_SIN, v+4, x}, {TW_SIN, v+5, x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, x}, \
	{TW_SIN, v+8, x}, {TW_SIN, v+9, x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, x}, \
	{TW_SIN, v+12, x}, {TW_SIN, v+13, x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, x}, \
	{TW_SIN, v+16, x}, {TW_SIN, v+17, x}, {TW_SIN, v+18, x}, {TW_SIN, v+19, x}, \
	{TW_SIN, v+20, x}, {TW_SIN, v+21, x}, {TW_SIN, v+22, x}, {TW_SIN, v+23, x}, \
	{TW_SIN, v+24, x}, {TW_SIN, v+25, x}, {TW_SIN, v+26, x}, {TW_SIN, v+27, x}, \
	{TW_SIN, v+28, x}, {TW_SIN, v+29, x}, {TW_SIN, v+30, x}, {TW_SIN, v+31, x}, \
	{TW_SIN, v+32, x}, {TW_SIN, v+33, x}, {TW_SIN, v+34, x}, {TW_SIN, v+35, x}, \
	{TW_SIN, v+36, x}, {TW_SIN, v+37, x}, {TW_SIN, v+38, x}, {TW_SIN, v+39, x}, \
	{TW_SIN, v+40, x}, {TW_SIN, v+41, x}, {TW_SIN, v+42, x}, {TW_SIN, v+43, x}, \
	{TW_SIN, v+44, x}, {TW_SIN, v+45, x}, {TW_SIN, v+46, x}, {TW_SIN, v+47, x}, \
	{TW_SIN, v+48, x}, {TW_SIN, v+49, x}, {TW_SIN, v+50, x}, {TW_SIN, v+51, x}, \
	{TW_SIN, v+52, x}, {TW_SIN, v+53, x}, {TW_SIN, v+54, x}, {TW_SIN, v+55, x}, \
	{TW_SIN, v+56, x}, {TW_SIN, v+57, x}, {TW_SIN, v+58, x}, {TW_SIN, v+59, x}, \
	{TW_SIN, v+60, x}, {TW_SIN, v+61, x}, {TW_SIN, v+62, x}, {TW_SIN, v+63, x}, \
	{TW_SIN, v+64, x}, {TW_SIN, v+65, x}, {TW_SIN, v+66, x}, {TW_SIN, v+67, x}, \
	{TW_SIN, v+68, x}, {TW_SIN, v+69, x}, {TW_SIN, v+70, x}, {TW_SIN, v+71, x}, \
	{TW_SIN, v+72, x}, {TW_SIN, v+73, x}, {TW_SIN, v+74, x}, {TW_SIN, v+75, x}, \
	{TW_SIN, v+76, x}, {TW_SIN, v+77, x}, {TW_SIN, v+78, x}, {TW_SIN, v+79, x}, \
	{TW_SIN, v+80, x}, {TW_SIN, v+81, x}, {TW_SIN, v+82, x}, {TW_SIN, v+83, x}, \
	{TW_SIN, v+84, x}, {TW_SIN, v+85, x}, {TW_SIN, v+86, x}, {TW_SIN, v+87, x}, \
	{TW_SIN, v+88, x}, {TW_SIN, v+89, x}, {TW_SIN, v+90, x}, {TW_SIN, v+91, x}, \
	{TW_SIN, v+92, x}, {TW_SIN, v+93, x}, {TW_SIN, v+94, x}, {TW_SIN, v+95, x}, \
	{TW_SIN, v+96, x}, {TW_SIN, v+97, x}, {TW_SIN, v+98, x}, {TW_SIN, v+99, x}, \
	{TW_SIN, v+100, x}, {TW_SIN, v+101, x}, {TW_SIN, v+102, x}, {TW_SIN, v+103, x}, \
	{TW_SIN, v+104, x}, {TW_SIN, v+105, x}, {TW_SIN, v+106, x}, {TW_SIN, v+107, x}, \
	{TW_SIN, v+108, x}, {TW_SIN, v+109, x}, {TW_SIN, v+110, x}, {TW_SIN, v+111, x}, \
	{TW_SIN, v+112, x}, {TW_SIN, v+113, x}, {TW_SIN, v+114, x}, {TW_SIN, v+115, x}, \
	{TW_SIN, v+116, x}, {TW_SIN, v+117, x}, {TW_SIN, v+118, x}, {TW_SIN, v+119, x}, \
	{TW_SIN, v+120, x}, {TW_SIN, v+121, x}, {TW_SIN, v+122, x}, {TW_SIN, v+123, x}, \
	{TW_SIN, v+124, x}, {TW_SIN, v+125, x}, {TW_SIN, v+126, x}, {TW_SIN, v+127, x} 
#endif // VTW_SIZE == 128
#if defined(VTW_SIZE) && VTW_SIZE == 256
#warning "using VTWS with 256"
#define VTWS(v,x) {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, \
	{TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, \
	{TW_COS, v+8, x}, {TW_COS, v+9, x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, \
	{TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, \
	{TW_COS, v+16, x}, {TW_COS, v+17, x}, {TW_COS, v+18, x}, {TW_COS, v+19, x}, \
	{TW_COS, v+20, x}, {TW_COS, v+21, x}, {TW_COS, v+22, x}, {TW_COS, v+23, x}, \
	{TW_COS, v+24, x}, {TW_COS, v+25, x}, {TW_COS, v+26, x}, {TW_COS, v+27, x}, \
	{TW_COS, v+28, x}, {TW_COS, v+29, x}, {TW_COS, v+30, x}, {TW_COS, v+31, x}, \
	{TW_COS, v+32, x}, {TW_COS, v+33, x}, {TW_COS, v+34, x}, {TW_COS, v+35, x}, \
	{TW_COS, v+36, x}, {TW_COS, v+37, x}, {TW_COS, v+38, x}, {TW_COS, v+39, x}, \
	{TW_COS, v+40, x}, {TW_COS, v+41, x}, {TW_COS, v+42, x}, {TW_COS, v+43, x}, \
	{TW_COS, v+44, x}, {TW_COS, v+45, x}, {TW_COS, v+46, x}, {TW_COS, v+47, x}, \
	{TW_COS, v+48, x}, {TW_COS, v+49, x}, {TW_COS, v+50, x}, {TW_COS, v+51, x}, \
	{TW_COS, v+52, x}, {TW_COS, v+53, x}, {TW_COS, v+54, x}, {TW_COS, v+55, x}, \
	{TW_COS, v+56, x}, {TW_COS, v+57, x}, {TW_COS, v+58, x}, {TW_COS, v+59, x}, \
	{TW_COS, v+60, x}, {TW_COS, v+61, x}, {TW_COS, v+62, x}, {TW_COS, v+63, x}, \
	{TW_COS, v+64, x}, {TW_COS, v+65, x}, {TW_COS, v+66, x}, {TW_COS, v+67, x}, \
	{TW_COS, v+68, x}, {TW_COS, v+69, x}, {TW_COS, v+70, x}, {TW_COS, v+71, x}, \
	{TW_COS, v+72, x}, {TW_COS, v+73, x}, {TW_COS, v+74, x}, {TW_COS, v+75, x}, \
	{TW_COS, v+76, x}, {TW_COS, v+77, x}, {TW_COS, v+78, x}, {TW_COS, v+79, x}, \
	{TW_COS, v+80, x}, {TW_COS, v+81, x}, {TW_COS, v+82, x}, {TW_COS, v+83, x}, \
	{TW_COS, v+84, x}, {TW_COS, v+85, x}, {TW_COS, v+86, x}, {TW_COS, v+87, x}, \
	{TW_COS, v+88, x}, {TW_COS, v+89, x}, {TW_COS, v+90, x}, {TW_COS, v+91, x}, \
	{TW_COS, v+92, x}, {TW_COS, v+93, x}, {TW_COS, v+94, x}, {TW_COS, v+95, x}, \
	{TW_COS, v+96, x}, {TW_COS, v+97, x}, {TW_COS, v+98, x}, {TW_COS, v+99, x}, \
	{TW_COS, v+100, x}, {TW_COS, v+101, x}, {TW_COS, v+102, x}, {TW_COS, v+103, x}, \
	{TW_COS, v+104, x}, {TW_COS, v+105, x}, {TW_COS, v+106, x}, {TW_COS, v+107, x}, \
	{TW_COS, v+108, x}, {TW_COS, v+109, x}, {TW_COS, v+110, x}, {TW_COS, v+111, x}, \
	{TW_COS, v+112, x}, {TW_COS, v+113, x}, {TW_COS, v+114, x}, {TW_COS, v+115, x}, \
	{TW_COS, v+116, x}, {TW_COS, v+117, x}, {TW_COS, v+118, x}, {TW_COS, v+119, x}, \
	{TW_COS, v+120, x}, {TW_COS, v+121, x}, {TW_COS, v+122, x}, {TW_COS, v+123, x}, \
	{TW_COS, v+124, x}, {TW_COS, v+125, x}, {TW_COS, v+126, x}, {TW_COS, v+127, x}, \
	{TW_COS, v+128, x}, {TW_COS, v+129, x}, {TW_COS, v+130, x}, {TW_COS, v+131, x}, \
	{TW_COS, v+132, x}, {TW_COS, v+133, x}, {TW_COS, v+134, x}, {TW_COS, v+135, x}, \
	{TW_COS, v+136, x}, {TW_COS, v+137, x}, {TW_COS, v+138, x}, {TW_COS, v+139, x}, \
	{TW_COS, v+140, x}, {TW_COS, v+141, x}, {TW_COS, v+142, x}, {TW_COS, v+143, x}, \
	{TW_COS, v+144, x}, {TW_COS, v+145, x}, {TW_COS, v+146, x}, {TW_COS, v+147, x}, \
	{TW_COS, v+148, x}, {TW_COS, v+149, x}, {TW_COS, v+150, x}, {TW_COS, v+151, x}, \
	{TW_COS, v+152, x}, {TW_COS, v+153, x}, {TW_COS, v+154, x}, {TW_COS, v+155, x}, \
	{TW_COS, v+156, x}, {TW_COS, v+157, x}, {TW_COS, v+158, x}, {TW_COS, v+159, x}, \
	{TW_COS, v+160, x}, {TW_COS, v+161, x}, {TW_COS, v+162, x}, {TW_COS, v+163, x}, \
	{TW_COS, v+164, x}, {TW_COS, v+165, x}, {TW_COS, v+166, x}, {TW_COS, v+167, x}, \
	{TW_COS, v+168, x}, {TW_COS, v+169, x}, {TW_COS, v+170, x}, {TW_COS, v+171, x}, \
	{TW_COS, v+172, x}, {TW_COS, v+173, x}, {TW_COS, v+174, x}, {TW_COS, v+175, x}, \
	{TW_COS, v+176, x}, {TW_COS, v+177, x}, {TW_COS, v+178, x}, {TW_COS, v+179, x}, \
	{TW_COS, v+180, x}, {TW_COS, v+181, x}, {TW_COS, v+182, x}, {TW_COS, v+183, x}, \
	{TW_COS, v+184, x}, {TW_COS, v+185, x}, {TW_COS, v+186, x}, {TW_COS, v+187, x}, \
	{TW_COS, v+188, x}, {TW_COS, v+189, x}, {TW_COS, v+190, x}, {TW_COS, v+191, x}, \
	{TW_COS, v+192, x}, {TW_COS, v+193, x}, {TW_COS, v+194, x}, {TW_COS, v+195, x}, \
	{TW_COS, v+196, x}, {TW_COS, v+197, x}, {TW_COS, v+198, x}, {TW_COS, v+199, x}, \
	{TW_COS, v+200, x}, {TW_COS, v+201, x}, {TW_COS, v+202, x}, {TW_COS, v+203, x}, \
	{TW_COS, v+204, x}, {TW_COS, v+205, x}, {TW_COS, v+206, x}, {TW_COS, v+207, x}, \
	{TW_COS, v+208, x}, {TW_COS, v+209, x}, {TW_COS, v+210, x}, {TW_COS, v+211, x}, \
	{TW_COS, v+212, x}, {TW_COS, v+213, x}, {TW_COS, v+214, x}, {TW_COS, v+215, x}, \
	{TW_COS, v+216, x}, {TW_COS, v+217, x}, {TW_COS, v+218, x}, {TW_COS, v+219, x}, \
	{TW_COS, v+220, x}, {TW_COS, v+221, x}, {TW_COS, v+222, x}, {TW_COS, v+223, x}, \
	{TW_COS, v+224, x}, {TW_COS, v+225, x}, {TW_COS, v+226, x}, {TW_COS, v+227, x}, \
	{TW_COS, v+228, x}, {TW_COS, v+229, x}, {TW_COS, v+230, x}, {TW_COS, v+231, x}, \
	{TW_COS, v+232, x}, {TW_COS, v+233, x}, {TW_COS, v+234, x}, {TW_COS, v+235, x}, \
	{TW_COS, v+236, x}, {TW_COS, v+237, x}, {TW_COS, v+238, x}, {TW_COS, v+239, x}, \
	{TW_COS, v+240, x}, {TW_COS, v+241, x}, {TW_COS, v+242, x}, {TW_COS, v+243, x}, \
	{TW_COS, v+244, x}, {TW_COS, v+245, x}, {TW_COS, v+246, x}, {TW_COS, v+247, x}, \
	{TW_COS, v+248, x}, {TW_COS, v+249, x}, {TW_COS, v+250, x}, {TW_COS, v+251, x}, \
	{TW_COS, v+252, x}, {TW_COS, v+253, x}, {TW_COS, v+254, x}, {TW_COS, v+255, x}, \
	{TW_SIN, v+0, x}, {TW_SIN, v+1, x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, x}, \
	{TW_SIN, v+4, x}, {TW_SIN, v+5, x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, x}, \
	{TW_SIN, v+8, x}, {TW_SIN, v+9, x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, x}, \
	{TW_SIN, v+12, x}, {TW_SIN, v+13, x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, x}, \
	{TW_SIN, v+16, x}, {TW_SIN, v+17, x}, {TW_SIN, v+18, x}, {TW_SIN, v+19, x}, \
	{TW_SIN, v+20, x}, {TW_SIN, v+21, x}, {TW_SIN, v+22, x}, {TW_SIN, v+23, x}, \
	{TW_SIN, v+24, x}, {TW_SIN, v+25, x}, {TW_SIN, v+26, x}, {TW_SIN, v+27, x}, \
	{TW_SIN, v+28, x}, {TW_SIN, v+29, x}, {TW_SIN, v+30, x}, {TW_SIN, v+31, x}, \
	{TW_SIN, v+32, x}, {TW_SIN, v+33, x}, {TW_SIN, v+34, x}, {TW_SIN, v+35, x}, \
	{TW_SIN, v+36, x}, {TW_SIN, v+37, x}, {TW_SIN, v+38, x}, {TW_SIN, v+39, x}, \
	{TW_SIN, v+40, x}, {TW_SIN, v+41, x}, {TW_SIN, v+42, x}, {TW_SIN, v+43, x}, \
	{TW_SIN, v+44, x}, {TW_SIN, v+45, x}, {TW_SIN, v+46, x}, {TW_SIN, v+47, x}, \
	{TW_SIN, v+48, x}, {TW_SIN, v+49, x}, {TW_SIN, v+50, x}, {TW_SIN, v+51, x}, \
	{TW_SIN, v+52, x}, {TW_SIN, v+53, x}, {TW_SIN, v+54, x}, {TW_SIN, v+55, x}, \
	{TW_SIN, v+56, x}, {TW_SIN, v+57, x}, {TW_SIN, v+58, x}, {TW_SIN, v+59, x}, \
	{TW_SIN, v+60, x}, {TW_SIN, v+61, x}, {TW_SIN, v+62, x}, {TW_SIN, v+63, x}, \
	{TW_SIN, v+64, x}, {TW_SIN, v+65, x}, {TW_SIN, v+66, x}, {TW_SIN, v+67, x}, \
	{TW_SIN, v+68, x}, {TW_SIN, v+69, x}, {TW_SIN, v+70, x}, {TW_SIN, v+71, x}, \
	{TW_SIN, v+72, x}, {TW_SIN, v+73, x}, {TW_SIN, v+74, x}, {TW_SIN, v+75, x}, \
	{TW_SIN, v+76, x}, {TW_SIN, v+77, x}, {TW_SIN, v+78, x}, {TW_SIN, v+79, x}, \
	{TW_SIN, v+80, x}, {TW_SIN, v+81, x}, {TW_SIN, v+82, x}, {TW_SIN, v+83, x}, \
	{TW_SIN, v+84, x}, {TW_SIN, v+85, x}, {TW_SIN, v+86, x}, {TW_SIN, v+87, x}, \
	{TW_SIN, v+88, x}, {TW_SIN, v+89, x}, {TW_SIN, v+90, x}, {TW_SIN, v+91, x}, \
	{TW_SIN, v+92, x}, {TW_SIN, v+93, x}, {TW_SIN, v+94, x}, {TW_SIN, v+95, x}, \
	{TW_SIN, v+96, x}, {TW_SIN, v+97, x}, {TW_SIN, v+98, x}, {TW_SIN, v+99, x}, \
	{TW_SIN, v+100, x}, {TW_SIN, v+101, x}, {TW_SIN, v+102, x}, {TW_SIN, v+103, x}, \
	{TW_SIN, v+104, x}, {TW_SIN, v+105, x}, {TW_SIN, v+106, x}, {TW_SIN, v+107, x}, \
	{TW_SIN, v+108, x}, {TW_SIN, v+109, x}, {TW_SIN, v+110, x}, {TW_SIN, v+111, x}, \
	{TW_SIN, v+112, x}, {TW_SIN, v+113, x}, {TW_SIN, v+114, x}, {TW_SIN, v+115, x}, \
	{TW_SIN, v+116, x}, {TW_SIN, v+117, x}, {TW_SIN, v+118, x}, {TW_SIN, v+119, x}, \
	{TW_SIN, v+120, x}, {TW_SIN, v+121, x}, {TW_SIN, v+122, x}, {TW_SIN, v+123, x}, \
	{TW_SIN, v+124, x}, {TW_SIN, v+125, x}, {TW_SIN, v+126, x}, {TW_SIN, v+127, x}, \
	{TW_SIN, v+128, x}, {TW_SIN, v+129, x}, {TW_SIN, v+130, x}, {TW_SIN, v+131, x}, \
	{TW_SIN, v+132, x}, {TW_SIN, v+133, x}, {TW_SIN, v+134, x}, {TW_SIN, v+135, x}, \
	{TW_SIN, v+136, x}, {TW_SIN, v+137, x}, {TW_SIN, v+138, x}, {TW_SIN, v+139, x}, \
	{TW_SIN, v+140, x}, {TW_SIN, v+141, x}, {TW_SIN, v+142, x}, {TW_SIN, v+143, x}, \
	{TW_SIN, v+144, x}, {TW_SIN, v+145, x}, {TW_SIN, v+146, x}, {TW_SIN, v+147, x}, \
	{TW_SIN, v+148, x}, {TW_SIN, v+149, x}, {TW_SIN, v+150, x}, {TW_SIN, v+151, x}, \
	{TW_SIN, v+152, x}, {TW_SIN, v+153, x}, {TW_SIN, v+154, x}, {TW_SIN, v+155, x}, \
	{TW_SIN, v+156, x}, {TW_SIN, v+157, x}, {TW_SIN, v+158, x}, {TW_SIN, v+159, x}, \
	{TW_SIN, v+160, x}, {TW_SIN, v+161, x}, {TW_SIN, v+162, x}, {TW_SIN, v+163, x}, \
	{TW_SIN, v+164, x}, {TW_SIN, v+165, x}, {TW_SIN, v+166, x}, {TW_SIN, v+167, x}, \
	{TW_SIN, v+168, x}, {TW_SIN, v+169, x}, {TW_SIN, v+170, x}, {TW_SIN, v+171, x}, \
	{TW_SIN, v+172, x}, {TW_SIN, v+173, x}, {TW_SIN, v+174, x}, {TW_SIN, v+175, x}, \
	{TW_SIN, v+176, x}, {TW_SIN, v+177, x}, {TW_SIN, v+178, x}, {TW_SIN, v+179, x}, \
	{TW_SIN, v+180, x}, {TW_SIN, v+181, x}, {TW_SIN, v+182, x}, {TW_SIN, v+183, x}, \
	{TW_SIN, v+184, x}, {TW_SIN, v+185, x}, {TW_SIN, v+186, x}, {TW_SIN, v+187, x}, \
	{TW_SIN, v+188, x}, {TW_SIN, v+189, x}, {TW_SIN, v+190, x}, {TW_SIN, v+191, x}, \
	{TW_SIN, v+192, x}, {TW_SIN, v+193, x}, {TW_SIN, v+194, x}, {TW_SIN, v+195, x}, \
	{TW_SIN, v+196, x}, {TW_SIN, v+197, x}, {TW_SIN, v+198, x}, {TW_SIN, v+199, x}, \
	{TW_SIN, v+200, x}, {TW_SIN, v+201, x}, {TW_SIN, v+202, x}, {TW_SIN, v+203, x}, \
	{TW_SIN, v+204, x}, {TW_SIN, v+205, x}, {TW_SIN, v+206, x}, {TW_SIN, v+207, x}, \
	{TW_SIN, v+208, x}, {TW_SIN, v+209, x}, {TW_SIN, v+210, x}, {TW_SIN, v+211, x}, \
	{TW_SIN, v+212, x}, {TW_SIN, v+213, x}, {TW_SIN, v+214, x}, {TW_SIN, v+215, x}, \
	{TW_SIN, v+216, x}, {TW_SIN, v+217, x}, {TW_SIN, v+218, x}, {TW_SIN, v+219, x}, \
	{TW_SIN, v+220, x}, {TW_SIN, v+221, x}, {TW_SIN, v+222, x}, {TW_SIN, v+223, x}, \
	{TW_SIN, v+224, x}, {TW_SIN, v+225, x}, {TW_SIN, v+226, x}, {TW_SIN, v+227, x}, \
	{TW_SIN, v+228, x}, {TW_SIN, v+229, x}, {TW_SIN, v+230, x}, {TW_SIN, v+231, x}, \
	{TW_SIN, v+232, x}, {TW_SIN, v+233, x}, {TW_SIN, v+234, x}, {TW_SIN, v+235, x}, \
	{TW_SIN, v+236, x}, {TW_SIN, v+237, x}, {TW_SIN, v+238, x}, {TW_SIN, v+239, x}, \
	{TW_SIN, v+240, x}, {TW_SIN, v+241, x}, {TW_SIN, v+242, x}, {TW_SIN, v+243, x}, \
	{TW_SIN, v+244, x}, {TW_SIN, v+245, x}, {TW_SIN, v+246, x}, {TW_SIN, v+247, x}, \
	{TW_SIN, v+248, x}, {TW_SIN, v+249, x}, {TW_SIN, v+250, x}, {TW_SIN, v+251, x}, \
	{TW_SIN, v+252, x}, {TW_SIN, v+253, x}, {TW_SIN, v+254, x}, {TW_SIN, v+255, x} 
#endif // VTW_SIZE == 256
#if defined(VTW_SIZE) && VTW_SIZE == 512
#warning "using VTWS with 512"
#define VTWS(v,x) {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, \
	{TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, \
	{TW_COS, v+8, x}, {TW_COS, v+9, x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, \
	{TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, \
	{TW_COS, v+16, x}, {TW_COS, v+17, x}, {TW_COS, v+18, x}, {TW_COS, v+19, x}, \
	{TW_COS, v+20, x}, {TW_COS, v+21, x}, {TW_COS, v+22, x}, {TW_COS, v+23, x}, \
	{TW_COS, v+24, x}, {TW_COS, v+25, x}, {TW_COS, v+26, x}, {TW_COS, v+27, x}, \
	{TW_COS, v+28, x}, {TW_COS, v+29, x}, {TW_COS, v+30, x}, {TW_COS, v+31, x}, \
	{TW_COS, v+32, x}, {TW_COS, v+33, x}, {TW_COS, v+34, x}, {TW_COS, v+35, x}, \
	{TW_COS, v+36, x}, {TW_COS, v+37, x}, {TW_COS, v+38, x}, {TW_COS, v+39, x}, \
	{TW_COS, v+40, x}, {TW_COS, v+41, x}, {TW_COS, v+42, x}, {TW_COS, v+43, x}, \
	{TW_COS, v+44, x}, {TW_COS, v+45, x}, {TW_COS, v+46, x}, {TW_COS, v+47, x}, \
	{TW_COS, v+48, x}, {TW_COS, v+49, x}, {TW_COS, v+50, x}, {TW_COS, v+51, x}, \
	{TW_COS, v+52, x}, {TW_COS, v+53, x}, {TW_COS, v+54, x}, {TW_COS, v+55, x}, \
	{TW_COS, v+56, x}, {TW_COS, v+57, x}, {TW_COS, v+58, x}, {TW_COS, v+59, x}, \
	{TW_COS, v+60, x}, {TW_COS, v+61, x}, {TW_COS, v+62, x}, {TW_COS, v+63, x}, \
	{TW_COS, v+64, x}, {TW_COS, v+65, x}, {TW_COS, v+66, x}, {TW_COS, v+67, x}, \
	{TW_COS, v+68, x}, {TW_COS, v+69, x}, {TW_COS, v+70, x}, {TW_COS, v+71, x}, \
	{TW_COS, v+72, x}, {TW_COS, v+73, x}, {TW_COS, v+74, x}, {TW_COS, v+75, x}, \
	{TW_COS, v+76, x}, {TW_COS, v+77, x}, {TW_COS, v+78, x}, {TW_COS, v+79, x}, \
	{TW_COS, v+80, x}, {TW_COS, v+81, x}, {TW_COS, v+82, x}, {TW_COS, v+83, x}, \
	{TW_COS, v+84, x}, {TW_COS, v+85, x}, {TW_COS, v+86, x}, {TW_COS, v+87, x}, \
	{TW_COS, v+88, x}, {TW_COS, v+89, x}, {TW_COS, v+90, x}, {TW_COS, v+91, x}, \
	{TW_COS, v+92, x}, {TW_COS, v+93, x}, {TW_COS, v+94, x}, {TW_COS, v+95, x}, \
	{TW_COS, v+96, x}, {TW_COS, v+97, x}, {TW_COS, v+98, x}, {TW_COS, v+99, x}, \
	{TW_COS, v+100, x}, {TW_COS, v+101, x}, {TW_COS, v+102, x}, {TW_COS, v+103, x}, \
	{TW_COS, v+104, x}, {TW_COS, v+105, x}, {TW_COS, v+106, x}, {TW_COS, v+107, x}, \
	{TW_COS, v+108, x}, {TW_COS, v+109, x}, {TW_COS, v+110, x}, {TW_COS, v+111, x}, \
	{TW_COS, v+112, x}, {TW_COS, v+113, x}, {TW_COS, v+114, x}, {TW_COS, v+115, x}, \
	{TW_COS, v+116, x}, {TW_COS, v+117, x}, {TW_COS, v+118, x}, {TW_COS, v+119, x}, \
	{TW_COS, v+120, x}, {TW_COS, v+121, x}, {TW_COS, v+122, x}, {TW_COS, v+123, x}, \
	{TW_COS, v+124, x}, {TW_COS, v+125, x}, {TW_COS, v+126, x}, {TW_COS, v+127, x}, \
	{TW_COS, v+128, x}, {TW_COS, v+129, x}, {TW_COS, v+130, x}, {TW_COS, v+131, x}, \
	{TW_COS, v+132, x}, {TW_COS, v+133, x}, {TW_COS, v+134, x}, {TW_COS, v+135, x}, \
	{TW_COS, v+136, x}, {TW_COS, v+137, x}, {TW_COS, v+138, x}, {TW_COS, v+139, x}, \
	{TW_COS, v+140, x}, {TW_COS, v+141, x}, {TW_COS, v+142, x}, {TW_COS, v+143, x}, \
	{TW_COS, v+144, x}, {TW_COS, v+145, x}, {TW_COS, v+146, x}, {TW_COS, v+147, x}, \
	{TW_COS, v+148, x}, {TW_COS, v+149, x}, {TW_COS, v+150, x}, {TW_COS, v+151, x}, \
	{TW_COS, v+152, x}, {TW_COS, v+153, x}, {TW_COS, v+154, x}, {TW_COS, v+155, x}, \
	{TW_COS, v+156, x}, {TW_COS, v+157, x}, {TW_COS, v+158, x}, {TW_COS, v+159, x}, \
	{TW_COS, v+160, x}, {TW_COS, v+161, x}, {TW_COS, v+162, x}, {TW_COS, v+163, x}, \
	{TW_COS, v+164, x}, {TW_COS, v+165, x}, {TW_COS, v+166, x}, {TW_COS, v+167, x}, \
	{TW_COS, v+168, x}, {TW_COS, v+169, x}, {TW_COS, v+170, x}, {TW_COS, v+171, x}, \
	{TW_COS, v+172, x}, {TW_COS, v+173, x}, {TW_COS, v+174, x}, {TW_COS, v+175, x}, \
	{TW_COS, v+176, x}, {TW_COS, v+177, x}, {TW_COS, v+178, x}, {TW_COS, v+179, x}, \
	{TW_COS, v+180, x}, {TW_COS, v+181, x}, {TW_COS, v+182, x}, {TW_COS, v+183, x}, \
	{TW_COS, v+184, x}, {TW_COS, v+185, x}, {TW_COS, v+186, x}, {TW_COS, v+187, x}, \
	{TW_COS, v+188, x}, {TW_COS, v+189, x}, {TW_COS, v+190, x}, {TW_COS, v+191, x}, \
	{TW_COS, v+192, x}, {TW_COS, v+193, x}, {TW_COS, v+194, x}, {TW_COS, v+195, x}, \
	{TW_COS, v+196, x}, {TW_COS, v+197, x}, {TW_COS, v+198, x}, {TW_COS, v+199, x}, \
	{TW_COS, v+200, x}, {TW_COS, v+201, x}, {TW_COS, v+202, x}, {TW_COS, v+203, x}, \
	{TW_COS, v+204, x}, {TW_COS, v+205, x}, {TW_COS, v+206, x}, {TW_COS, v+207, x}, \
	{TW_COS, v+208, x}, {TW_COS, v+209, x}, {TW_COS, v+210, x}, {TW_COS, v+211, x}, \
	{TW_COS, v+212, x}, {TW_COS, v+213, x}, {TW_COS, v+214, x}, {TW_COS, v+215, x}, \
	{TW_COS, v+216, x}, {TW_COS, v+217, x}, {TW_COS, v+218, x}, {TW_COS, v+219, x}, \
	{TW_COS, v+220, x}, {TW_COS, v+221, x}, {TW_COS, v+222, x}, {TW_COS, v+223, x}, \
	{TW_COS, v+224, x}, {TW_COS, v+225, x}, {TW_COS, v+226, x}, {TW_COS, v+227, x}, \
	{TW_COS, v+228, x}, {TW_COS, v+229, x}, {TW_COS, v+230, x}, {TW_COS, v+231, x}, \
	{TW_COS, v+232, x}, {TW_COS, v+233, x}, {TW_COS, v+234, x}, {TW_COS, v+235, x}, \
	{TW_COS, v+236, x}, {TW_COS, v+237, x}, {TW_COS, v+238, x}, {TW_COS, v+239, x}, \
	{TW_COS, v+240, x}, {TW_COS, v+241, x}, {TW_COS, v+242, x}, {TW_COS, v+243, x}, \
	{TW_COS, v+244, x}, {TW_COS, v+245, x}, {TW_COS, v+246, x}, {TW_COS, v+247, x}, \
	{TW_COS, v+248, x}, {TW_COS, v+249, x}, {TW_COS, v+250, x}, {TW_COS, v+251, x}, \
	{TW_COS, v+252, x}, {TW_COS, v+253, x}, {TW_COS, v+254, x}, {TW_COS, v+255, x}, \
	{TW_COS, v+256, x}, {TW_COS, v+257, x}, {TW_COS, v+258, x}, {TW_COS, v+259, x}, \
	{TW_COS, v+260, x}, {TW_COS, v+261, x}, {TW_COS, v+262, x}, {TW_COS, v+263, x}, \
	{TW_COS, v+264, x}, {TW_COS, v+265, x}, {TW_COS, v+266, x}, {TW_COS, v+267, x}, \
	{TW_COS, v+268, x}, {TW_COS, v+269, x}, {TW_COS, v+270, x}, {TW_COS, v+271, x}, \
	{TW_COS, v+272, x}, {TW_COS, v+273, x}, {TW_COS, v+274, x}, {TW_COS, v+275, x}, \
	{TW_COS, v+276, x}, {TW_COS, v+277, x}, {TW_COS, v+278, x}, {TW_COS, v+279, x}, \
	{TW_COS, v+280, x}, {TW_COS, v+281, x}, {TW_COS, v+282, x}, {TW_COS, v+283, x}, \
	{TW_COS, v+284, x}, {TW_COS, v+285, x}, {TW_COS, v+286, x}, {TW_COS, v+287, x}, \
	{TW_COS, v+288, x}, {TW_COS, v+289, x}, {TW_COS, v+290, x}, {TW_COS, v+291, x}, \
	{TW_COS, v+292, x}, {TW_COS, v+293, x}, {TW_COS, v+294, x}, {TW_COS, v+295, x}, \
	{TW_COS, v+296, x}, {TW_COS, v+297, x}, {TW_COS, v+298, x}, {TW_COS, v+299, x}, \
	{TW_COS, v+300, x}, {TW_COS, v+301, x}, {TW_COS, v+302, x}, {TW_COS, v+303, x}, \
	{TW_COS, v+304, x}, {TW_COS, v+305, x}, {TW_COS, v+306, x}, {TW_COS, v+307, x}, \
	{TW_COS, v+308, x}, {TW_COS, v+309, x}, {TW_COS, v+310, x}, {TW_COS, v+311, x}, \
	{TW_COS, v+312, x}, {TW_COS, v+313, x}, {TW_COS, v+314, x}, {TW_COS, v+315, x}, \
	{TW_COS, v+316, x}, {TW_COS, v+317, x}, {TW_COS, v+318, x}, {TW_COS, v+319, x}, \
	{TW_COS, v+320, x}, {TW_COS, v+321, x}, {TW_COS, v+322, x}, {TW_COS, v+323, x}, \
	{TW_COS, v+324, x}, {TW_COS, v+325, x}, {TW_COS, v+326, x}, {TW_COS, v+327, x}, \
	{TW_COS, v+328, x}, {TW_COS, v+329, x}, {TW_COS, v+330, x}, {TW_COS, v+331, x}, \
	{TW_COS, v+332, x}, {TW_COS, v+333, x}, {TW_COS, v+334, x}, {TW_COS, v+335, x}, \
	{TW_COS, v+336, x}, {TW_COS, v+337, x}, {TW_COS, v+338, x}, {TW_COS, v+339, x}, \
	{TW_COS, v+340, x}, {TW_COS, v+341, x}, {TW_COS, v+342, x}, {TW_COS, v+343, x}, \
	{TW_COS, v+344, x}, {TW_COS, v+345, x}, {TW_COS, v+346, x}, {TW_COS, v+347, x}, \
	{TW_COS, v+348, x}, {TW_COS, v+349, x}, {TW_COS, v+350, x}, {TW_COS, v+351, x}, \
	{TW_COS, v+352, x}, {TW_COS, v+353, x}, {TW_COS, v+354, x}, {TW_COS, v+355, x}, \
	{TW_COS, v+356, x}, {TW_COS, v+357, x}, {TW_COS, v+358, x}, {TW_COS, v+359, x}, \
	{TW_COS, v+360, x}, {TW_COS, v+361, x}, {TW_COS, v+362, x}, {TW_COS, v+363, x}, \
	{TW_COS, v+364, x}, {TW_COS, v+365, x}, {TW_COS, v+366, x}, {TW_COS, v+367, x}, \
	{TW_COS, v+368, x}, {TW_COS, v+369, x}, {TW_COS, v+370, x}, {TW_COS, v+371, x}, \
	{TW_COS, v+372, x}, {TW_COS, v+373, x}, {TW_COS, v+374, x}, {TW_COS, v+375, x}, \
	{TW_COS, v+376, x}, {TW_COS, v+377, x}, {TW_COS, v+378, x}, {TW_COS, v+379, x}, \
	{TW_COS, v+380, x}, {TW_COS, v+381, x}, {TW_COS, v+382, x}, {TW_COS, v+383, x}, \
	{TW_COS, v+384, x}, {TW_COS, v+385, x}, {TW_COS, v+386, x}, {TW_COS, v+387, x}, \
	{TW_COS, v+388, x}, {TW_COS, v+389, x}, {TW_COS, v+390, x}, {TW_COS, v+391, x}, \
	{TW_COS, v+392, x}, {TW_COS, v+393, x}, {TW_COS, v+394, x}, {TW_COS, v+395, x}, \
	{TW_COS, v+396, x}, {TW_COS, v+397, x}, {TW_COS, v+398, x}, {TW_COS, v+399, x}, \
	{TW_COS, v+400, x}, {TW_COS, v+401, x}, {TW_COS, v+402, x}, {TW_COS, v+403, x}, \
	{TW_COS, v+404, x}, {TW_COS, v+405, x}, {TW_COS, v+406, x}, {TW_COS, v+407, x}, \
	{TW_COS, v+408, x}, {TW_COS, v+409, x}, {TW_COS, v+410, x}, {TW_COS, v+411, x}, \
	{TW_COS, v+412, x}, {TW_COS, v+413, x}, {TW_COS, v+414, x}, {TW_COS, v+415, x}, \
	{TW_COS, v+416, x}, {TW_COS, v+417, x}, {TW_COS, v+418, x}, {TW_COS, v+419, x}, \
	{TW_COS, v+420, x}, {TW_COS, v+421, x}, {TW_COS, v+422, x}, {TW_COS, v+423, x}, \
	{TW_COS, v+424, x}, {TW_COS, v+425, x}, {TW_COS, v+426, x}, {TW_COS, v+427, x}, \
	{TW_COS, v+428, x}, {TW_COS, v+429, x}, {TW_COS, v+430, x}, {TW_COS, v+431, x}, \
	{TW_COS, v+432, x}, {TW_COS, v+433, x}, {TW_COS, v+434, x}, {TW_COS, v+435, x}, \
	{TW_COS, v+436, x}, {TW_COS, v+437, x}, {TW_COS, v+438, x}, {TW_COS, v+439, x}, \
	{TW_COS, v+440, x}, {TW_COS, v+441, x}, {TW_COS, v+442, x}, {TW_COS, v+443, x}, \
	{TW_COS, v+444, x}, {TW_COS, v+445, x}, {TW_COS, v+446, x}, {TW_COS, v+447, x}, \
	{TW_COS, v+448, x}, {TW_COS, v+449, x}, {TW_COS, v+450, x}, {TW_COS, v+451, x}, \
	{TW_COS, v+452, x}, {TW_COS, v+453, x}, {TW_COS, v+454, x}, {TW_COS, v+455, x}, \
	{TW_COS, v+456, x}, {TW_COS, v+457, x}, {TW_COS, v+458, x}, {TW_COS, v+459, x}, \
	{TW_COS, v+460, x}, {TW_COS, v+461, x}, {TW_COS, v+462, x}, {TW_COS, v+463, x}, \
	{TW_COS, v+464, x}, {TW_COS, v+465, x}, {TW_COS, v+466, x}, {TW_COS, v+467, x}, \
	{TW_COS, v+468, x}, {TW_COS, v+469, x}, {TW_COS, v+470, x}, {TW_COS, v+471, x}, \
	{TW_COS, v+472, x}, {TW_COS, v+473, x}, {TW_COS, v+474, x}, {TW_COS, v+475, x}, \
	{TW_COS, v+476, x}, {TW_COS, v+477, x}, {TW_COS, v+478, x}, {TW_COS, v+479, x}, \
	{TW_COS, v+480, x}, {TW_COS, v+481, x}, {TW_COS, v+482, x}, {TW_COS, v+483, x}, \
	{TW_COS, v+484, x}, {TW_COS, v+485, x}, {TW_COS, v+486, x}, {TW_COS, v+487, x}, \
	{TW_COS, v+488, x}, {TW_COS, v+489, x}, {TW_COS, v+490, x}, {TW_COS, v+491, x}, \
	{TW_COS, v+492, x}, {TW_COS, v+493, x}, {TW_COS, v+494, x}, {TW_COS, v+495, x}, \
	{TW_COS, v+496, x}, {TW_COS, v+497, x}, {TW_COS, v+498, x}, {TW_COS, v+499, x}, \
	{TW_COS, v+500, x}, {TW_COS, v+501, x}, {TW_COS, v+502, x}, {TW_COS, v+503, x}, \
	{TW_COS, v+504, x}, {TW_COS, v+505, x}, {TW_COS, v+506, x}, {TW_COS, v+507, x}, \
	{TW_COS, v+508, x}, {TW_COS, v+509, x}, {TW_COS, v+510, x}, {TW_COS, v+511, x}, \
	{TW_SIN, v+0, x}, {TW_SIN, v+1, x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, x}, \
	{TW_SIN, v+4, x}, {TW_SIN, v+5, x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, x}, \
	{TW_SIN, v+8, x}, {TW_SIN, v+9, x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, x}, \
	{TW_SIN, v+12, x}, {TW_SIN, v+13, x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, x}, \
	{TW_SIN, v+16, x}, {TW_SIN, v+17, x}, {TW_SIN, v+18, x}, {TW_SIN, v+19, x}, \
	{TW_SIN, v+20, x}, {TW_SIN, v+21, x}, {TW_SIN, v+22, x}, {TW_SIN, v+23, x}, \
	{TW_SIN, v+24, x}, {TW_SIN, v+25, x}, {TW_SIN, v+26, x}, {TW_SIN, v+27, x}, \
	{TW_SIN, v+28, x}, {TW_SIN, v+29, x}, {TW_SIN, v+30, x}, {TW_SIN, v+31, x}, \
	{TW_SIN, v+32, x}, {TW_SIN, v+33, x}, {TW_SIN, v+34, x}, {TW_SIN, v+35, x}, \
	{TW_SIN, v+36, x}, {TW_SIN, v+37, x}, {TW_SIN, v+38, x}, {TW_SIN, v+39, x}, \
	{TW_SIN, v+40, x}, {TW_SIN, v+41, x}, {TW_SIN, v+42, x}, {TW_SIN, v+43, x}, \
	{TW_SIN, v+44, x}, {TW_SIN, v+45, x}, {TW_SIN, v+46, x}, {TW_SIN, v+47, x}, \
	{TW_SIN, v+48, x}, {TW_SIN, v+49, x}, {TW_SIN, v+50, x}, {TW_SIN, v+51, x}, \
	{TW_SIN, v+52, x}, {TW_SIN, v+53, x}, {TW_SIN, v+54, x}, {TW_SIN, v+55, x}, \
	{TW_SIN, v+56, x}, {TW_SIN, v+57, x}, {TW_SIN, v+58, x}, {TW_SIN, v+59, x}, \
	{TW_SIN, v+60, x}, {TW_SIN, v+61, x}, {TW_SIN, v+62, x}, {TW_SIN, v+63, x}, \
	{TW_SIN, v+64, x}, {TW_SIN, v+65, x}, {TW_SIN, v+66, x}, {TW_SIN, v+67, x}, \
	{TW_SIN, v+68, x}, {TW_SIN, v+69, x}, {TW_SIN, v+70, x}, {TW_SIN, v+71, x}, \
	{TW_SIN, v+72, x}, {TW_SIN, v+73, x}, {TW_SIN, v+74, x}, {TW_SIN, v+75, x}, \
	{TW_SIN, v+76, x}, {TW_SIN, v+77, x}, {TW_SIN, v+78, x}, {TW_SIN, v+79, x}, \
	{TW_SIN, v+80, x}, {TW_SIN, v+81, x}, {TW_SIN, v+82, x}, {TW_SIN, v+83, x}, \
	{TW_SIN, v+84, x}, {TW_SIN, v+85, x}, {TW_SIN, v+86, x}, {TW_SIN, v+87, x}, \
	{TW_SIN, v+88, x}, {TW_SIN, v+89, x}, {TW_SIN, v+90, x}, {TW_SIN, v+91, x}, \
	{TW_SIN, v+92, x}, {TW_SIN, v+93, x}, {TW_SIN, v+94, x}, {TW_SIN, v+95, x}, \
	{TW_SIN, v+96, x}, {TW_SIN, v+97, x}, {TW_SIN, v+98, x}, {TW_SIN, v+99, x}, \
	{TW_SIN, v+100, x}, {TW_SIN, v+101, x}, {TW_SIN, v+102, x}, {TW_SIN, v+103, x}, \
	{TW_SIN, v+104, x}, {TW_SIN, v+105, x}, {TW_SIN, v+106, x}, {TW_SIN, v+107, x}, \
	{TW_SIN, v+108, x}, {TW_SIN, v+109, x}, {TW_SIN, v+110, x}, {TW_SIN, v+111, x}, \
	{TW_SIN, v+112, x}, {TW_SIN, v+113, x}, {TW_SIN, v+114, x}, {TW_SIN, v+115, x}, \
	{TW_SIN, v+116, x}, {TW_SIN, v+117, x}, {TW_SIN, v+118, x}, {TW_SIN, v+119, x}, \
	{TW_SIN, v+120, x}, {TW_SIN, v+121, x}, {TW_SIN, v+122, x}, {TW_SIN, v+123, x}, \
	{TW_SIN, v+124, x}, {TW_SIN, v+125, x}, {TW_SIN, v+126, x}, {TW_SIN, v+127, x}, \
	{TW_SIN, v+128, x}, {TW_SIN, v+129, x}, {TW_SIN, v+130, x}, {TW_SIN, v+131, x}, \
	{TW_SIN, v+132, x}, {TW_SIN, v+133, x}, {TW_SIN, v+134, x}, {TW_SIN, v+135, x}, \
	{TW_SIN, v+136, x}, {TW_SIN, v+137, x}, {TW_SIN, v+138, x}, {TW_SIN, v+139, x}, \
	{TW_SIN, v+140, x}, {TW_SIN, v+141, x}, {TW_SIN, v+142, x}, {TW_SIN, v+143, x}, \
	{TW_SIN, v+144, x}, {TW_SIN, v+145, x}, {TW_SIN, v+146, x}, {TW_SIN, v+147, x}, \
	{TW_SIN, v+148, x}, {TW_SIN, v+149, x}, {TW_SIN, v+150, x}, {TW_SIN, v+151, x}, \
	{TW_SIN, v+152, x}, {TW_SIN, v+153, x}, {TW_SIN, v+154, x}, {TW_SIN, v+155, x}, \
	{TW_SIN, v+156, x}, {TW_SIN, v+157, x}, {TW_SIN, v+158, x}, {TW_SIN, v+159, x}, \
	{TW_SIN, v+160, x}, {TW_SIN, v+161, x}, {TW_SIN, v+162, x}, {TW_SIN, v+163, x}, \
	{TW_SIN, v+164, x}, {TW_SIN, v+165, x}, {TW_SIN, v+166, x}, {TW_SIN, v+167, x}, \
	{TW_SIN, v+168, x}, {TW_SIN, v+169, x}, {TW_SIN, v+170, x}, {TW_SIN, v+171, x}, \
	{TW_SIN, v+172, x}, {TW_SIN, v+173, x}, {TW_SIN, v+174, x}, {TW_SIN, v+175, x}, \
	{TW_SIN, v+176, x}, {TW_SIN, v+177, x}, {TW_SIN, v+178, x}, {TW_SIN, v+179, x}, \
	{TW_SIN, v+180, x}, {TW_SIN, v+181, x}, {TW_SIN, v+182, x}, {TW_SIN, v+183, x}, \
	{TW_SIN, v+184, x}, {TW_SIN, v+185, x}, {TW_SIN, v+186, x}, {TW_SIN, v+187, x}, \
	{TW_SIN, v+188, x}, {TW_SIN, v+189, x}, {TW_SIN, v+190, x}, {TW_SIN, v+191, x}, \
	{TW_SIN, v+192, x}, {TW_SIN, v+193, x}, {TW_SIN, v+194, x}, {TW_SIN, v+195, x}, \
	{TW_SIN, v+196, x}, {TW_SIN, v+197, x}, {TW_SIN, v+198, x}, {TW_SIN, v+199, x}, \
	{TW_SIN, v+200, x}, {TW_SIN, v+201, x}, {TW_SIN, v+202, x}, {TW_SIN, v+203, x}, \
	{TW_SIN, v+204, x}, {TW_SIN, v+205, x}, {TW_SIN, v+206, x}, {TW_SIN, v+207, x}, \
	{TW_SIN, v+208, x}, {TW_SIN, v+209, x}, {TW_SIN, v+210, x}, {TW_SIN, v+211, x}, \
	{TW_SIN, v+212, x}, {TW_SIN, v+213, x}, {TW_SIN, v+214, x}, {TW_SIN, v+215, x}, \
	{TW_SIN, v+216, x}, {TW_SIN, v+217, x}, {TW_SIN, v+218, x}, {TW_SIN, v+219, x}, \
	{TW_SIN, v+220, x}, {TW_SIN, v+221, x}, {TW_SIN, v+222, x}, {TW_SIN, v+223, x}, \
	{TW_SIN, v+224, x}, {TW_SIN, v+225, x}, {TW_SIN, v+226, x}, {TW_SIN, v+227, x}, \
	{TW_SIN, v+228, x}, {TW_SIN, v+229, x}, {TW_SIN, v+230, x}, {TW_SIN, v+231, x}, \
	{TW_SIN, v+232, x}, {TW_SIN, v+233, x}, {TW_SIN, v+234, x}, {TW_SIN, v+235, x}, \
	{TW_SIN, v+236, x}, {TW_SIN, v+237, x}, {TW_SIN, v+238, x}, {TW_SIN, v+239, x}, \
	{TW_SIN, v+240, x}, {TW_SIN, v+241, x}, {TW_SIN, v+242, x}, {TW_SIN, v+243, x}, \
	{TW_SIN, v+244, x}, {TW_SIN, v+245, x}, {TW_SIN, v+246, x}, {TW_SIN, v+247, x}, \
	{TW_SIN, v+248, x}, {TW_SIN, v+249, x}, {TW_SIN, v+250, x}, {TW_SIN, v+251, x}, \
	{TW_SIN, v+252, x}, {TW_SIN, v+253, x}, {TW_SIN, v+254, x}, {TW_SIN, v+255, x}, \
	{TW_SIN, v+256, x}, {TW_SIN, v+257, x}, {TW_SIN, v+258, x}, {TW_SIN, v+259, x}, \
	{TW_SIN, v+260, x}, {TW_SIN, v+261, x}, {TW_SIN, v+262, x}, {TW_SIN, v+263, x}, \
	{TW_SIN, v+264, x}, {TW_SIN, v+265, x}, {TW_SIN, v+266, x}, {TW_SIN, v+267, x}, \
	{TW_SIN, v+268, x}, {TW_SIN, v+269, x}, {TW_SIN, v+270, x}, {TW_SIN, v+271, x}, \
	{TW_SIN, v+272, x}, {TW_SIN, v+273, x}, {TW_SIN, v+274, x}, {TW_SIN, v+275, x}, \
	{TW_SIN, v+276, x}, {TW_SIN, v+277, x}, {TW_SIN, v+278, x}, {TW_SIN, v+279, x}, \
	{TW_SIN, v+280, x}, {TW_SIN, v+281, x}, {TW_SIN, v+282, x}, {TW_SIN, v+283, x}, \
	{TW_SIN, v+284, x}, {TW_SIN, v+285, x}, {TW_SIN, v+286, x}, {TW_SIN, v+287, x}, \
	{TW_SIN, v+288, x}, {TW_SIN, v+289, x}, {TW_SIN, v+290, x}, {TW_SIN, v+291, x}, \
	{TW_SIN, v+292, x}, {TW_SIN, v+293, x}, {TW_SIN, v+294, x}, {TW_SIN, v+295, x}, \
	{TW_SIN, v+296, x}, {TW_SIN, v+297, x}, {TW_SIN, v+298, x}, {TW_SIN, v+299, x}, \
	{TW_SIN, v+300, x}, {TW_SIN, v+301, x}, {TW_SIN, v+302, x}, {TW_SIN, v+303, x}, \
	{TW_SIN, v+304, x}, {TW_SIN, v+305, x}, {TW_SIN, v+306, x}, {TW_SIN, v+307, x}, \
	{TW_SIN, v+308, x}, {TW_SIN, v+309, x}, {TW_SIN, v+310, x}, {TW_SIN, v+311, x}, \
	{TW_SIN, v+312, x}, {TW_SIN, v+313, x}, {TW_SIN, v+314, x}, {TW_SIN, v+315, x}, \
	{TW_SIN, v+316, x}, {TW_SIN, v+317, x}, {TW_SIN, v+318, x}, {TW_SIN, v+319, x}, \
	{TW_SIN, v+320, x}, {TW_SIN, v+321, x}, {TW_SIN, v+322, x}, {TW_SIN, v+323, x}, \
	{TW_SIN, v+324, x}, {TW_SIN, v+325, x}, {TW_SIN, v+326, x}, {TW_SIN, v+327, x}, \
	{TW_SIN, v+328, x}, {TW_SIN, v+329, x}, {TW_SIN, v+330, x}, {TW_SIN, v+331, x}, \
	{TW_SIN, v+332, x}, {TW_SIN, v+333, x}, {TW_SIN, v+334, x}, {TW_SIN, v+335, x}, \
	{TW_SIN, v+336, x}, {TW_SIN, v+337, x}, {TW_SIN, v+338, x}, {TW_SIN, v+339, x}, \
	{TW_SIN, v+340, x}, {TW_SIN, v+341, x}, {TW_SIN, v+342, x}, {TW_SIN, v+343, x}, \
	{TW_SIN, v+344, x}, {TW_SIN, v+345, x}, {TW_SIN, v+346, x}, {TW_SIN, v+347, x}, \
	{TW_SIN, v+348, x}, {TW_SIN, v+349, x}, {TW_SIN, v+350, x}, {TW_SIN, v+351, x}, \
	{TW_SIN, v+352, x}, {TW_SIN, v+353, x}, {TW_SIN, v+354, x}, {TW_SIN, v+355, x}, \
	{TW_SIN, v+356, x}, {TW_SIN, v+357, x}, {TW_SIN, v+358, x}, {TW_SIN, v+359, x}, \
	{TW_SIN, v+360, x}, {TW_SIN, v+361, x}, {TW_SIN, v+362, x}, {TW_SIN, v+363, x}, \
	{TW_SIN, v+364, x}, {TW_SIN, v+365, x}, {TW_SIN, v+366, x}, {TW_SIN, v+367, x}, \
	{TW_SIN, v+368, x}, {TW_SIN, v+369, x}, {TW_SIN, v+370, x}, {TW_SIN, v+371, x}, \
	{TW_SIN, v+372, x}, {TW_SIN, v+373, x}, {TW_SIN, v+374, x}, {TW_SIN, v+375, x}, \
	{TW_SIN, v+376, x}, {TW_SIN, v+377, x}, {TW_SIN, v+378, x}, {TW_SIN, v+379, x}, \
	{TW_SIN, v+380, x}, {TW_SIN, v+381, x}, {TW_SIN, v+382, x}, {TW_SIN, v+383, x}, \
	{TW_SIN, v+384, x}, {TW_SIN, v+385, x}, {TW_SIN, v+386, x}, {TW_SIN, v+387, x}, \
	{TW_SIN, v+388, x}, {TW_SIN, v+389, x}, {TW_SIN, v+390, x}, {TW_SIN, v+391, x}, \
	{TW_SIN, v+392, x}, {TW_SIN, v+393, x}, {TW_SIN, v+394, x}, {TW_SIN, v+395, x}, \
	{TW_SIN, v+396, x}, {TW_SIN, v+397, x}, {TW_SIN, v+398, x}, {TW_SIN, v+399, x}, \
	{TW_SIN, v+400, x}, {TW_SIN, v+401, x}, {TW_SIN, v+402, x}, {TW_SIN, v+403, x}, \
	{TW_SIN, v+404, x}, {TW_SIN, v+405, x}, {TW_SIN, v+406, x}, {TW_SIN, v+407, x}, \
	{TW_SIN, v+408, x}, {TW_SIN, v+409, x}, {TW_SIN, v+410, x}, {TW_SIN, v+411, x}, \
	{TW_SIN, v+412, x}, {TW_SIN, v+413, x}, {TW_SIN, v+414, x}, {TW_SIN, v+415, x}, \
	{TW_SIN, v+416, x}, {TW_SIN, v+417, x}, {TW_SIN, v+418, x}, {TW_SIN, v+419, x}, \
	{TW_SIN, v+420, x}, {TW_SIN, v+421, x}, {TW_SIN, v+422, x}, {TW_SIN, v+423, x}, \
	{TW_SIN, v+424, x}, {TW_SIN, v+425, x}, {TW_SIN, v+426, x}, {TW_SIN, v+427, x}, \
	{TW_SIN, v+428, x}, {TW_SIN, v+429, x}, {TW_SIN, v+430, x}, {TW_SIN, v+431, x}, \
	{TW_SIN, v+432, x}, {TW_SIN, v+433, x}, {TW_SIN, v+434, x}, {TW_SIN, v+435, x}, \
	{TW_SIN, v+436, x}, {TW_SIN, v+437, x}, {TW_SIN, v+438, x}, {TW_SIN, v+439, x}, \
	{TW_SIN, v+440, x}, {TW_SIN, v+441, x}, {TW_SIN, v+442, x}, {TW_SIN, v+443, x}, \
	{TW_SIN, v+444, x}, {TW_SIN, v+445, x}, {TW_SIN, v+446, x}, {TW_SIN, v+447, x}, \
	{TW_SIN, v+448, x}, {TW_SIN, v+449, x}, {TW_SIN, v+450, x}, {TW_SIN, v+451, x}, \
	{TW_SIN, v+452, x}, {TW_SIN, v+453, x}, {TW_SIN, v+454, x}, {TW_SIN, v+455, x}, \
	{TW_SIN, v+456, x}, {TW_SIN, v+457, x}, {TW_SIN, v+458, x}, {TW_SIN, v+459, x}, \
	{TW_SIN, v+460, x}, {TW_SIN, v+461, x}, {TW_SIN, v+462, x}, {TW_SIN, v+463, x}, \
	{TW_SIN, v+464, x}, {TW_SIN, v+465, x}, {TW_SIN, v+466, x}, {TW_SIN, v+467, x}, \
	{TW_SIN, v+468, x}, {TW_SIN, v+469, x}, {TW_SIN, v+470, x}, {TW_SIN, v+471, x}, \
	{TW_SIN, v+472, x}, {TW_SIN, v+473, x}, {TW_SIN, v+474, x}, {TW_SIN, v+475, x}, \
	{TW_SIN, v+476, x}, {TW_SIN, v+477, x}, {TW_SIN, v+478, x}, {TW_SIN, v+479, x}, \
	{TW_SIN, v+480, x}, {TW_SIN, v+481, x}, {TW_SIN, v+482, x}, {TW_SIN, v+483, x}, \
	{TW_SIN, v+484, x}, {TW_SIN, v+485, x}, {TW_SIN, v+486, x}, {TW_SIN, v+487, x}, \
	{TW_SIN, v+488, x}, {TW_SIN, v+489, x}, {TW_SIN, v+490, x}, {TW_SIN, v+491, x}, \
	{TW_SIN, v+492, x}, {TW_SIN, v+493, x}, {TW_SIN, v+494, x}, {TW_SIN, v+495, x}, \
	{TW_SIN, v+496, x}, {TW_SIN, v+497, x}, {TW_SIN, v+498, x}, {TW_SIN, v+499, x}, \
	{TW_SIN, v+500, x}, {TW_SIN, v+501, x}, {TW_SIN, v+502, x}, {TW_SIN, v+503, x}, \
	{TW_SIN, v+504, x}, {TW_SIN, v+505, x}, {TW_SIN, v+506, x}, {TW_SIN, v+507, x}, \
	{TW_SIN, v+508, x}, {TW_SIN, v+509, x}, {TW_SIN, v+510, x}, {TW_SIN, v+511, x} 
#endif // VTW_SIZE == 512
#endif // REQ_VTWS
